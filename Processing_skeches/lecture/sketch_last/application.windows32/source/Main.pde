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
    speed = 3.0;
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
  
  void Initialize(){
    counter = 0;
    p_counter = -100;
    distance = 0;
    scoreinterval = 40;
    speeduptiming = 50;
    speed = 3.0;
    alp = 0;
    p.Initialize();
    floor[0].Initialize();
    bgm1.play();
  }
  
  void Finalize(){
    bgm1.pause();
    bgm1.rewind();
  }
  
  void Update(){
    if(bgm1.position() >= 135300){
      bgm1.play(23445);
    }
    
    for(int i = 0;i<floor.length;i++){
      floor[i].Update();
      if(floor[i].nextfloor && floor[i].posX + floor[i].f_width/2 < width - 50){
        floor[i].nextfloor = false;
        for(int t = 0;t<floor.length;t++){
          if(!floor[t].flag){
            floor[t].Initialize(int(random(0,5)),speed);
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
        speed += 1.0;
        p.Paceup();
        if(scoreinterval >= 20) scoreinterval -= 10;
      }
    }
    
  }
  
  void Draw(){
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
  
  boolean isHonF(float hx,float hy,float fx,float fw,float fh){
    if(hx > fx-fw/2 && hx < fx+fw/2 && hy >= fh){
      return true;
    }else{
      return false;
    }
  }
  
  int Readfile(){
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
        s = int(m);
      }
    }
    return s;
  }
  
  void debugtextdraw(){
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
