import ddf.minim.spi.*;
import ddf.minim.signals.*;
import ddf.minim.*;
import ddf.minim.analysis.*;
import ddf.minim.ugens.*;
import ddf.minim.effects.*;

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

void setup(){
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

void draw(){
  background(255);
  gamestate.Update();
  gamestate.Draw();
  if(!p_keyState['q'%256] && keyState['q'%256]) debugmode = !debugmode;
  for(int i = 0;i<256;i++){
    p_keyState[i] = keyState[i]; 
  }
}

void keyPressed(){
  if(0<=key && key<256){
    keyState[key] = true;
  }else if(0<=keyCode && keyCode<256){
    keyState[keyCode] = true;
  }    
}

void keyReleased(){
  if(0<=key && key<256){
    keyState[key] = false;
  }else if(0<=keyCode && keyCode<256){
    keyState[keyCode] = false;
  }
}

void stop(){
  bgm1.close();
  bgm2.close();
  minim.stop();
  super.stop();
}




