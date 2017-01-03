PFont font;
String msg = "Makise Riho";
int last;

void setup(){
  size(400,200);
  font = loadFont("Serif.plain-48.vlw");
  textFont(font,36);
  textAlign(CENTER,CENTER);
  last = 0;
}

void draw(){
  background(255);
  fill(0);
  text(msg.substring(0,last+1),0,0,width,height);
}

void mouseClicked(){
  last = (last+1)%msg.length();
}
