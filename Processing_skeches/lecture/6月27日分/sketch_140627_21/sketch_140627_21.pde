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
  switch(key){
    case 'a':{
      sine.setFreq(440.0);
      break;
    }
    case 's':{
      sine.setFreq(466.163762);
      break;
    }
    case 'd':{
      sine.setFreq(493.883301);
      break;
    }
    case 'f':{
      sine.setFreq(523.251131);
      break;
    }
    case 'g':{
      sine.setFreq(554.36522);
      break;
    }
    case 'h':{
      sine.setFreq(587.329536);
      break;
    }
    case 'j':{
      sine.setFreq(622.253967);
      break;
    }
    case 'k':{
      sine.setFreq(659.255114);
      break;
    }
    case 'l':{
      sine.setFreq(698.456463);
      break;
    }
    case ';':{
      sine.setFreq(739.988845);
      break;
    }
    case ':':{
      sine.setFreq(783.990872);
      break;
    }
    case ']':{
      sine.setFreq(830.609395);
      break;
    }
    case 'q':{
      sine.setFreq(880.0);
      break;
    }
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
