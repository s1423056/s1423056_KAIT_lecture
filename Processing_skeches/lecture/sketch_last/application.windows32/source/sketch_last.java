import processing.core.*; 
import processing.data.*; 
import processing.event.*; 
import processing.opengl.*; 

import ddf.minim.spi.*; 
import ddf.minim.signals.*; 
import ddf.minim.*; 
import ddf.minim.analysis.*; 
import ddf.minim.ugens.*; 
import ddf.minim.effects.*; 

import java.util.HashMap; 
import java.util.ArrayList; 
import java.io.File; 
import java.io.BufferedReader; 
import java.io.PrintWriter; 
import java.io.InputStream; 
import java.io.OutputStream; 
import java.io.IOException; 

public class sketch_last extends PApplet {








Task gamestate;
Player p;
Floor[] floor;

Minim minim;
AudioPlayer bgm1,bgm2;

boolean keyState[];
boolean p_keyState[];
int counter = 0;
int st = 0;
int H_imgsize = 64;
boolean debugmode = false;

public void setup(){
  size(600,400);
  
  minim = new Minim(this);
  bgm1 = minim.loadFile("bgm1.mp3");
  bgm2 = minim.loadFile("bgm2.mp3");
  
  textAlign(CENTER);
  textSize(40);
  fill(0);
  imageMode(CENTER);
  
  keyState = new boolean[256];
  p_keyState = new boolean[256];
  for(int t = 0;t<keyState.length;t++){
    keyState[t] = false;
    p_keyState[t] = false;
  }
  gamestate = new Title();
}

public void draw(){
  background(255);
  gamestate.Update();
  gamestate.Draw();
  if(!p_keyState['q'%256] && keyState['q'%256]) debugmode = !debugmode;
  for(int i = 0;i<256;i++){
    p_keyState[i] = keyState[i]; 
  }
}

public void keyPressed(){
  if(0<=key && key<256){
    keyState[key] = true;
  }else if(0<=keyCode && keyCode<256){
    keyState[keyCode] = true;
  }    
}

public void keyReleased(){
  if(0<=key && key<256){
    keyState[key] = false;
  }else if(0<=keyCode && keyCode<256){
    keyState[keyCode] = false;
  }
}

public void stop(){
  bgm1.close();
  bgm2.close();
  minim.stop();
  super.stop();
}




class Basestate implements Task{
  public void Initialize(){};
  public void Finalize(){};
  public void Update(){};
  public void Draw(){};
}
class Floor extends Objects{
  boolean flag;
  boolean nextfloor;
  float vX;
  float f_width;
  float f_height;
  
  public void Initialize(){
    flag = true;
    nextfloor = true;
    vX = 3.0f;
    f_width = 1000;
    f_height = 100;
    posX = width/2;
    posY = height;
  }
  
  public void Initialize(int num,float v){
    flag = true;
    nextfloor = true;
    vX = v;
    
    posY = height;
    switch(num){
      case 0:
        f_width = 400;
        f_height = 100;
        break;
      case 1:
        f_width = 300;
        f_height = 50;
        break;
      case 2:
        f_width = 200;
        f_height = 100;
        break;
      case 3:
        f_width = 400;
        f_height =50;
        break;
      case 4:
        f_width = 300;
        f_height = 100;
        break;
      default:
        f_width = 600;
        f_height = 100;
        break;
    }
    posX = width + 2*f_width/3+random(-50,50);
  }
  
  public void Finalize(){
    flag = false;
    nextfloor = false;
    posX = 0;
    posY = 0;
    f_width = 0;
    f_height = 0;
  }
  
  public void Update(){
    posX -= vX;
  }
  
  public void Draw(){
    if(flag){
      strokeWeight(2);
      fill(0,0,255,50);
      rectMode(CENTER);
      rect(posX,posY,f_width,f_height);
    }
  }
}
class Gameover extends Basestate {
  boolean newrecord;
  int score;
  int hiscore;
  
  Gameover(int s,int h){
    score = s;
    hiscore = h;
    if(score >= hiscore){
      newrecord = true;
    }else{
      newrecord = false;
    }
    if(newrecord){
      Writefile();
    }
    bgm2.play();
  }
  
  public void Initialize(){
    bgm2.play();
  }
  
  public void Finalize(){
    bgm2.pause();
    bgm2.rewind();
  }
  
  public void Writefile(){
    PrintWriter output;
    output = createWriter("data/score.txt");
    
    output.println(hiscore);
    output.flush();
    output.close();
    println("Newrecord was saved.");
  }
  
  public void Update(){
    if(!p_keyState['z'%256] && keyState['z'%256]){
      Finalize();
      gamestate = new Title();
    }
  }
  
  public void Draw(){
    textAlign(CENTER);
    fill(0);
    textSize(40);
    text("GAME OVER",width/2,height/2-50);
    textSize(30);
    text("your score : "+score+"m",width/2,height/2+50);
    textSize(20);
    text("press Z key to return to Title",width/2,height/2+180);
    
    if(newrecord){
      fill(255,0,0);
      textSize(40);
      text("New Record!",width/2,height/2+120);
    }
  }
}
class Main extends Basestate {
  int counter;
  int p_counter;
  int hiscore;
  int distance;
  int scoreinterval;
  int speeduptiming;
  float speed;
  int alp;
  
  Main(){
    counter = 0;
    hiscore = Readfile();
    distance = 0;
    scoreinterval = 40;
    speeduptiming = 50;
    speed = 3.0f;
    alp = 0;
    p_counter = -100;
    
    p = new Player();
    p.Initialize();
    floor = new Floor[4];
    for(int i = 0;i<floor.length;i++){
      floor[i] = new Floor();
    }
    floor[0].Initialize();
    bgm1.play();
  }
  
  public void Initialize(){
    counter = 0;
    p_counter = -100;
    distance = 0;
    scoreinterval = 40;
    speeduptiming = 50;
    speed = 3.0f;
    alp = 0;
    p.Initialize();
    floor[0].Initialize();
    bgm1.play();
  }
  
  public void Finalize(){
    bgm1.pause();
    bgm1.rewind();
  }
  
  public void Update(){
    if(bgm1.position() >= 135300){
      bgm1.play(23445);
    }
    
    for(int i = 0;i<floor.length;i++){
      floor[i].Update();
      if(floor[i].nextfloor && floor[i].posX + floor[i].f_width/2 < width - 50){
        floor[i].nextfloor = false;
        for(int t = 0;t<floor.length;t++){
          if(!floor[t].flag){
            floor[t].Initialize(PApplet.parseInt(random(0,5)),speed);
            break;
          }
        }
      }
      if(floor[i].posX + floor[i].f_width/2 < 0)floor[i].Finalize();
    }
    
    p.Update();
    if(p.posY > 1000){
      if(alp < 800){
        alp +=5 ;
      }else{
        Finalize();
        gamestate = new Gameover(distance,hiscore);
      }
    }
    
    counter++;
    if(counter % scoreinterval == 0 && p.posY < height){
      distance++;
      if(distance >= hiscore) hiscore = distance;
      if(distance % speeduptiming == 0){
        p_counter = counter;
        speeduptiming *= 2;
        speed += 1.0f;
        p.Paceup();
        if(scoreinterval >= 20) scoreinterval -= 10;
      }
    }
    
  }
  
  public void Draw(){
    fill(0);
    textAlign(CENTER);
    if(counter < 100) text("start!",width/2,height/2);
    if(counter < p_counter+100) text("speed up!",width/2,height/2);
    for(int i = 0;i<floor.length;i++){
      floor[i].Draw();
    }
    p.Draw();
    
    if(debugmode){
      debugtextdraw();
    }else{
      rectMode(CORNER);
      fill(255);
      rect(0,0,250,30);
      rect(0,30,250,30);
      
      textSize(30);
      fill(0);
      
      textAlign(LEFT);
      text("hiscore:",5,26);
      text("score:",5,55);
      textAlign(RIGHT);
      text(hiscore+"m",250,27);
      text(distance+"m",250,57);
    }
    
    rectMode(CORNER);
    noStroke();
    fill(0,0,0,alp);
    rect(0,0,width,height);
    stroke(0);
  }
  
  public boolean isHonF(float hx,float hy,float fx,float fw,float fh){
    if(hx > fx-fw/2 && hx < fx+fw/2 && hy >= fh){
      return true;
    }else{
      return false;
    }
  }
  
  public int Readfile(){
    BufferedReader input;
    String line;
    int s = 0;
    input = createReader("score.txt");
    boolean f = true;
    
    while(f){
      try{
        line = input.readLine();
      }catch(IOException e){
        e.printStackTrace();
        line = null;
      }
      if(line == null){
        f = false;
      }else{
        String m = line;
        s = PApplet.parseInt(m);
      }
    }
    return s;
  }
  
  public void debugtextdraw(){
    fill(0);
    textSize(15);
    textAlign(LEFT);
    
    text("p.posX:"+p.posX,10,12);
    text("p.posY:"+p.posY,10,32);
    text("p.vY:"+p.vY,10,52);
    if(p.sjump){
      text("sjump == true ",10,72);
    }else{
      text("sjump == false",10,72);
    }
    
    text("counter:"+counter,10,102);
    text("speed:"+speed,10,132);
    
    text("floor[0].posX:"+floor[0].posX,150,12);
    text("floor[0].f_width:"+floor[0].f_width,150,32);
    text("floor[1].posX:"+floor[1].posX,350,12);
    text("floor[1].f_width:"+floor[1].f_width,350,32);
    text("floor[2].posX:"+floor[2].posX,150,72);
    text("floor[2].f_width:"+floor[2].f_width,150,92);
    text("floor[3].posX:"+floor[3].posX,350,72);
    text("floor[3].f_width:"+floor[3].f_width,350,92);
  }
}
class Objects{
  float posX,posY;
  public void Initialize(){}
  public void Finalize(){}
  public void Update(){}
  public void Draw(){}
  
}
class Player extends Objects{
  int counter,i,pace;
  float vX,vY,aY;
  boolean isFRY,sjump;
  PImage img[],jmp;

  Player(){
    img = new PImage[16];
    for(int i = 1;i<16;i++){
      img[i] = loadImage("h_w_r"+i+".png");
    }
    img[0] = loadImage("h_w_1.png");
    jmp = loadImage("h_w_j.png");
  }
  
   public void Initialize(){
    i = 0;
    pace = 4;
    isFRY = true;
    sjump = true;
    vX = 2.5f;
    vY = 0;
    aY = 0.3f;
    posX = width/4;
    posY = height/2;
  }
  
  public void Finalize(){}
  
  public void Update(){
      counter++;
    
    if(!isFRY){
      vY = 0;
      if(keyState['z'%256]){
        isFRY = true;
        vY = 7.0f;
      }
    }else{
      if(sjump && !p_keyState['z'%256] && keyState['z'%256]){
        sjump = false;
        vY = 7.0f;
      }
      vY -= aY;
    }
    posY -= vY; 
    
    for(int i = 0;i<floor.length;i++){
      float fx = floor[i].posX;
      float fxl = floor[i].posX - floor[i].f_width/2;
      float fxr = floor[i].posX + floor[i].f_width/2;
      float fh = floor[i].posY - floor[i].f_height/2;
      if(posY+H_imgsize/2 > fh){
        if(posX > fx && posX < fxr+5){
          posX = fxr+5;
        }else if(posX < fx && posX > fxl-5){
          posX = fxl-5;
        }
      }else if(vY <= 0 && posY+H_imgsize/2 < fh +10 && posY+H_imgsize/2 > fh -10){
          if(posX > fxl-10 && posX < fxr+10){
            posY = fh - H_imgsize/2;
            isFRY = false;
            sjump = true;
            break;
          }else{
            isFRY = true;
        }
      }
    }
    
    if(counter >= pace){
      counter = 0;
      if(!isFRY && i < img.length){
        i++;
        if(i == img.length)i = 4;
      }
    }
  }
  
  public void Draw(){
    if(isFRY){
      image(jmp,posX,posY);
    }else{
      image(img[i],posX,posY);
    }
  }
  
  public void Paceup(){
    if(pace > 1) pace--;
    if(aY < 0.4f) aY += 0.02f;
  }
}
interface Task{
  public void Initialize();
  public void Finalize();
  public void Update();
  public void Draw();
}
class Title extends Basestate{
  int counter = 0;
  boolean start = false;
  
  public void Initialize(){}
  public void Finalize(){}
  
  public void Update(){
    if(!p_keyState['z'%256] && keyState['z'%256]){
      start = true;
    }
    if(start)counter++;
    if(counter >= 180){
      gamestate = new Main();
    }
  }
  
  public void Draw(){
    textAlign(CENTER);
    textSize(40);
    fill(0);
    if(start){
      text((240-counter)/60,width/2,height/2);
    }else{
      text("The Runner",width/2,height/2-40);
      textSize(25);
      text("press Z key to Game Start",width/2,height/2+100);
    }
  }
}
  static public void main(String[] passedArgs) {
    String[] appletArgs = new String[] { "sketch_last" };
    if (passedArgs != null) {
      PApplet.main(concat(appletArgs, passedArgs));
    } else {
      PApplet.main(appletArgs);
    }
  }
}
