String[] msgs = {"Kanagawa",
                 "Institute",
                 "of",
                 "Technology"};
PFont font;
int msgId;
int x,y;

void setup(){
  size(400,200);
  smooth();
  font = loadFont("HGSMinchoB-48.vlw");
  textFont(font,36);
  msgId = int(random(msgs.length));
  y = int(random(height));
  x = width;
}

void draw(){
  background(255);
  x--;
  if(x+textWidth(msgs[msgId]) < 0){
    x = width;
    y = int(random(textAscent(),
            height-textDescent()));
    msgId = int(random(msgs.length));
  }
  fill(0);
  text(msgs[msgId],x,y);
}
