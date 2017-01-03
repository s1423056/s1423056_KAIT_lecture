import ddf.minim.*;
import ddf.minim.signals.*;
import ddf.minim.analysis.*;
import ddf.minim.effects.*;
Minim minim;
AudioPlayer player;
PFont font;

void setup(){
  size(100,100);
  minim = new Minim(this);
  player = minim.loadFile( "groove.mp3" );
  font = loadFont("Serif.plain-48.vlw");
  textFont(font,24);
  textAlign(CENTER);
}

void draw(){
  background(255);
  if(player.isPlaying()){
    fill(50);
    text("Playing",width/2,height/2);
  }
}

void mouseClicked(){
  player.rewind();
  player.loop();
}

void stop(){
  player.close();
  minim.stop();
  super.stop();
}
