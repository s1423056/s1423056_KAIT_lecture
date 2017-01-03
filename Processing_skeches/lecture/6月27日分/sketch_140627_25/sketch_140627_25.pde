PFont font;

void setup(){
  size(400,200);
  smooth();
  font = loadFont("Serif.plain-48.vlw") ;
  textFont(font,48);
}

void draw(){
  background(255);
  int h = hour();
  int m = minute();
  int s = second();
  String time = nf(hour(),2) +":"+ nf(minute(),2) +":"+ nf(second(),2) ;
  fill(0);
  textAlign(CENTER);
  text(time,width/2,height/2);
}
