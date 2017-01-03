import ddf.minim.spi.*;
import ddf.minim.signals.*;
import ddf.minim.*;
import ddf.minim.analysis.*;
import ddf.minim.ugens.*;
import ddf.minim.effects.*;

PFont font;
float xTarget;
float yTarget;
int targetWidth;
int targetHeight;
color targetColor;

int GAME_READY = 0;
int GAME_UPDATING = 1;
int GAME_RUNNING = 2;
int GAME_HIT = 3;
int GAME_END = 4;
int currentState;

Minim minim;
AudioSample p1,p2;

int time0_msec;
float p_rand;
float rand_min;
float rand_max;
int HitCount,missHitCount;
int Hit_max = 0;

void startElapsedTime(){
  time0_msec = millis();
}

int elapsedTime_msec(){
  return millis()-time0_msec;
}

void setup(){
  size(400,400);
  smooth();
  font = createFont("Serif",48);
  currentState = GAME_READY;
  minim = new Minim(this);
  p1 = minim.loadSample("appear01.wav");
  p2 = minim.loadSample("appear04.wav");
  GameInitialize();
}

void GameInitialize(){
  p_rand = 0;
  rand_max = 5000;
  rand_min = 3000;
  HitCount = 0;
  missHitCount = 0;
}

void updateTarget(){
  targetWidth = 50;
  targetHeight = 50;
  xTarget = random(targetWidth,width-targetWidth);
  yTarget = random(targetHeight,height-targetHeight);
  targetColor = color(10,10,255);
  p_rand = random(rand_min,rand_max);
}

boolean isOnTarget(int x,int y){
  if((x-xTarget)*(x-xTarget)+(y-yTarget)*(y-yTarget) < (25*25)){
    return true;
  }else{
    return false;
  }
}

void showReadyMessage(){
  textAlign(CENTER);
  textFont(font,48);
  fill(0);
  text("Start to click",width/2,height/2);
  textSize(30);
  text("MAX score : " + Hit_max,width/2,height-30);
}

void showHitMessage(){
  textAlign(CENTER);
  textFont(font,48);
  fill(255,10,10);
  text("Hit!!",width/2,height/2);
}

void showTarget(){
  stroke(targetColor);
  fill(targetColor);
  //rectMode(CORNER);
  ellipse(xTarget,yTarget,50,50);
}

void showGameENDMessage(){
  fill(255,10,10);
  text("GAME OVER",width/2,height/2);
  fill(0);
  text("score : " + HitCount,width/2,height-30);
}

void draw(){
  background(255);
  if(currentState == GAME_READY){
    showReadyMessage();
  }else if(currentState == GAME_UPDATING){
    updateTarget();
    currentState = GAME_RUNNING;
    startElapsedTime();
  }else if(currentState == GAME_RUNNING){
    showTarget();
    textSize(30);
    fill(0);
    text("Time : "+ int(p_rand-elapsedTime_msec()),width/2,40);
    text("Hit : "+ HitCount,width-50,40);
    text("Miss : "+ missHitCount,width-50,80);
    if(elapsedTime_msec() >= p_rand){
      missHitCount++;
      p2.trigger();
      currentState = GAME_UPDATING;
      if(missHitCount >= 5){
        currentState = GAME_END;
      }else{
        currentState = GAME_UPDATING;
      }
    }
  }else if(currentState == GAME_HIT){
    showHitMessage();
    if(elapsedTime_msec() > 0 && elapsedTime_msec() < 20) p1.trigger();
    if(elapsedTime_msec() >= 500){
      currentState = GAME_UPDATING;
      HitCount++;
      if(rand_max > 1000){
        rand_max = p_rand-100;
      }else{
        rand_max -= 50;
      }
      if(rand_min > 100)rand_min = p_rand-300;
    }
  }else if(currentState == GAME_END){
    showGameENDMessage();
    if(elapsedTime_msec() >= 5000){
      if(HitCount > Hit_max) Hit_max = HitCount;
      GameInitialize();
      currentState = GAME_READY;
    }
  }
}

void mouseClicked(){
  if(currentState == GAME_READY){
    currentState = GAME_UPDATING;
  }else if(currentState == GAME_RUNNING){
    if(isOnTarget(mouseX,mouseY)){
      currentState = GAME_HIT;
      startElapsedTime();
    }
  }
}

void stop(){
  p1.close();
  p2.close();
  minim.stop();
  super.stop();
}
