import ddf.minim.*;
import ddf.minim.signals.*;
import ddf.minim.analysis.*;
import ddf.minim.effects.*;
Minim minim;
AudioPlayer player;

void setup(){
  size(100,100);
  minim = new Minim(this);
  player = minim.loadFile( "groove.mp3" );
}

void draw(){
}

void mouseClicked(){
  player.loop();
}

void stop(){
  player.close();
  minim.stop();
  super.stop();
}
