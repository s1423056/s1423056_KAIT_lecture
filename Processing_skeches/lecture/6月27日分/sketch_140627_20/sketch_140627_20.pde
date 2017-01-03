import ddf.minim.*;
import ddf.minim.signals.*;
import ddf.minim.analysis.*;
import ddf.minim.effects.*;
Minim minim;
AudioSample se;
int xBall;
int vBall;
int rBall=15;
color cBall;

void setup(){
  minim = new Minim(this);
  se = minim.loadSample( "score.wav" );
  size(400,200);
  smooth();
  colorMode(HSB,359,99,99);
  xBall=width/2;
  vBall = 1;
  cBall = color(random(360),99,99);
}

void draw(){
  background(0,0,99);
  xBall += vBall;
  if( xBall-rBall <= 0 ){
    xBall = rBall ;
    vBall = 1;
    se.trigger();
    cBall = color(random(360),99,99);
  }else if( xBall+rBall >= width ){
    xBall = width-rBall;
    vBall = -1;
    se.trigger();
    cBall = color(random(360),99,99);
  }
  stroke(cBall);
  fill(cBall);
  ellipse(xBall,height/2,2*rBall,2*rBall);
}

void stop(){
  se.close(); // ライン出力の機能を終了する
  minim.stop(); // Minim の機能を停止する
  super.stop(); // 停止の際のおまじない
}
