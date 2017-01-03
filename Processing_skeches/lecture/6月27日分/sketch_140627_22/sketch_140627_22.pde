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
  sine = new SineWave ( 0 , 5.0, out.sampleRate() );
  out.addSignal(sine);
  ringingStart = 0;
}

void draw(){
  if(second() == 57 || second() == 58 || second() == 59){
    sine.setFreq(440);
    ringingStart = millis();
  }else if(second() == 0){
    sine.setFreq(880);
    ringingStart = millis();
  }
  if(millis() - ringingStart > 100){
    sine.setFreq(0);
  }
}

void stop(){
  out.close();
  minim.stop();
  super.stop();
}
