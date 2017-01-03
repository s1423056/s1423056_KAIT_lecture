import ddf.minim.*;
import ddf.minim.signals.*;
import ddf.minim.analysis.*;
import ddf.minim.effects.*;
Minim minim;
AudioOutput out;
SineWave sine;
int ringingStart;

void setup(){
  minim = new Minim(this);
  out = minim.getLineOut(Minim.STEREO);
  sine = new SineWave( 880 , 5.5, out.sampleRate() );
  out.addSignal(sine);
  out.mute();
}

void draw(){
  if(millis()-ringingStart > 100){
    out.mute();
  }
}

void mouseClicked(){
  ringingStart = millis();
  out.unmute();
}

void stop(){
  out.close();
  minim.stop();
  super.stop();
}
