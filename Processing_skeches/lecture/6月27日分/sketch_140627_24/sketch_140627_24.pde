import ddf.minim.spi.*;
import ddf.minim.signals.*;
import ddf.minim.*;
import ddf.minim.analysis.*;
import ddf.minim.ugens.*;
import ddf.minim.effects.*;

Minim minim;
AudioOutput out;
SineWave sine;

void setup(){
  minim = new Minim(this);
  out = minim.getLineOut(Minim.STEREO);
  sine = new SineWave ( 440 , 10.0 , out.sampleRate() );
  out.addSignal(sine);
  out.noSound();
}

void draw(){
  
}

void mousePressed(){
  out.sound();
}

void mouseReleased(){
  out.noSound();
}

void stop(){
  out.close();
  minim.stop();
  super.stop();
}
