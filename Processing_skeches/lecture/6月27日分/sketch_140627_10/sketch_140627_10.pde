import ddf.minim.*;
import ddf.minim.signals.*;
import ddf.minim.analysis.*;
import ddf.minim.effects.*;
Minim minim;
AudioSample sSound;

void setup(){
  size(200,200);
  minim = new Minim(this);
  sSound = minim.loadSample( "score.wav" );
}

void draw(){
  background(255);
  stroke(0);
  fill(120);
  ellipse(width/2,height/2,100,100);
}

void mouseClicked(){
   if(dist(width/2,height/2,mouseX,mouseY) < 50){
     sSound.trigger();
   }
}

void stop(){
  sSound.close();
  minim.stop();
  super.stop();
}
