String[] msgs = {"Kanagawa",
                 "Institute",
                 "of",
                 "Technology"};
PFont font;
String msg;
int x,y;

void setup(){
  size(400,200);
  smooth();
  font = loadFont("HGSMinchoB-48.vlw");
  textFont(font,36);
  msg =msgs[int(random(msgs.length ))];
  y = int(random(height));
  x = width;
}

void draw(){
  background(255);
  x--;
  if(x+textWidth(msg) < 0){
    x = width;
    y =int(random(textAscent(),
    height-textDescent()));
    msg=msgs[ int (random(msgs.length ))];
  }
  fill(0);
  text( msg ,x,y);
}
