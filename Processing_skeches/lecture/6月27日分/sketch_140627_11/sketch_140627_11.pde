import ddf.minim.*;
import ddf.minim.signals.*;
import ddf.minim.analysis.*;
import ddf.minim.effects.*;
Minim minim;
AudioSample[] se;
int radiusBall = 40;
int[] xBall;
color[] cBall;

void setup(){
  minim = new Minim(this);
  size(400,200);
  smooth();
  se = new AudioSample[3] ;
  se[0] = minim.loadSample( "score.wav" );
  se[1] = minim.loadSample( "damage.wav" );
  se[2] = minim.loadSample( "totaled.wav" );
  xBall = new int[3] ;
  for(int i=0;i<3;i++){
    xBall[i] = (width/4)*(i+1) ;
  }
  cBall = new color[3] ;
  cBall[0] = color(10,255,10);
  cBall[1] = color(255,255,10);
  cBall[2] = color(255,10,10);
}

void draw(){
  background(255);
  for(int i=0;i<3;i++){
    stroke( cBall[i] );
    fill( cBall[i] );
    ellipse(xBall[i],height/2,2*radiusBall,2*radiusBall);
  }
}

void mouseClicked(){
  for(int i=0;i<3;i++){
    if(dist( xBall[i] , height/2 ,mouseX,mouseY) < radiusBall ){
      se[i].trigger();
      break;
    }
  }
}

void stop(){
  for(int i=0;i<3;i++){
    se[i].close();
  }
  minim.stop();
  super.stop();
}
