import ddf.minim.*;
import ddf.minim.signals.*;
import ddf.minim.analysis.*;
import ddf.minim.effects.*;
Minim minim;
AudioOutput out;
SineWave sine;

void setup(){
  minim = new Minim(this);
  out = minim.getLineOut(Minim.STEREO);
  sine = new SineWave( 440 , 5.5, out.sampleRate() );
  out.addSignal(sine);
  sine.setFreq(0);
}

void draw(){
}

void mousePressed(){
  sine.setFreq(440);
}

void mouseReleased(){
  sine.setFreq(0);
}

void stop(){
  out.close();
  minim.stop();
  super.stop();
}
