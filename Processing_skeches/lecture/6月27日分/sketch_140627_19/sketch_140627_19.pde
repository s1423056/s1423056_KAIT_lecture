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
  sine = new SineWave( 0 , 5.5, out.sampleRate() );
  out.addSignal(sine);
}

void draw(){

}

void keyPressed(){
  if(key == '1'){
    sine.setFreq(440);
  }else if(key == '2'){
    sine.setFreq(880);
  }
}

void keyReleased(){
  sine.setFreq(0);
}

void stop(){
  out.close();
  minim.stop();
  super.stop();
}
