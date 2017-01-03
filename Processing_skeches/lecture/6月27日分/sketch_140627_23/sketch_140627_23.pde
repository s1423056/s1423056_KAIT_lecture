import ddf.minim.spi.*;
import ddf.minim.signals.*;
import ddf.minim.*;
import ddf.minim.analysis.*;
import ddf.minim.ugens.*;
import ddf.minim.effects.*;

float x;
float y;
float r;
int c;
int count;

float bx,by,br;
boolean bf;

Minim minim;
AudioPlayer player;
AudioSample se1,se2;

void setup(){
  size(400,400);
  y = -20;
  x = 200;
  r = 20;
  c = 0;
  bx = 0;
  by = 0;
  br = 10;
  bf = false;
  count = 0;
  
  minim = new Minim(this);
  player = minim.loadFile("弾02：不可能弾幕には反則を.wav");
  se1 = minim.loadSample("beam.wav");
  se2 = minim.loadSample("explosion.wav");
  
  player.loop();
}

void draw(){
  background(0);
  noStroke();
  fill(10,10,255);
  triangle( mouseX,mouseY-20,mouseX-14,mouseY+20,mouseX+14,mouseY+20);
  fill(255,0,0);
  ellipse(x,y,r,r);
  y++;
  if(bf){
    fill(255,255,0);
    ellipse(bx,by,br,br);
    by-=3;
    if(by < -br*2) bf = false;
  }
  collision();
  fill(255);
  textSize(20);
  text("score:" + count,20,20);
  println(count);
}

void mouseClicked(){
  if(bf == false){
    bx = mouseX;
    by = mouseY;
    bf = true;
    se1.trigger();
  }
}

void collision(){
  if( ((y-by)*(y-by) + (x-bx)*(x-bx)) < (((r+br)/2)*((r+br)/2))  ){
    y = -50;
    x = random(50,width-50);
    r = random(20,40);
    bf = false;
    se2.trigger();
    count++;
  }
}

void stop(){
  player.close();
  se1.close();
  se2.close();
  minim.stop();
  super.stop(); 
}
