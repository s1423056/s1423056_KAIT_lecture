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
  sine = new SineWave ( 880 , 0.5, out.sampleRate() );
  out.addSignal(sine);
}

void draw(){
}

void stop(){
  out.close();
  minim.stop();
  super.stop();
}
