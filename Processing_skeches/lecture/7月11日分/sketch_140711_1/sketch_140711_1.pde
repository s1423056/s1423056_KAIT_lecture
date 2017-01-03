PFont font;
String[] lines;

void setup(){
  size(400,400);
  font = loadFont("Serif.plain-48.vlw");
  textFont(font, 36);
  lines = loadStrings("name.txt");
}

void draw(){
  background(255);
  fill(0);
  text(lines[0],30,50,width - 30,50);
  text(lines[1],30,100,width - 30,50);
}
