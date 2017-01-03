String[] msgs = {"abc",
                 "efg",
                 "hij",
                 "klm",
                 "nop",
                 "qrs",
                 "tuv",
                 "wxy",
                 "zzz"};
color c;
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
  c = color(0,0,0);
}

void draw(){
  background(255);
  x-=5;
  if(x+textWidth(msgs[msgId]) < 0){
    c = color(int(random(0,256)),int(random(0,256)),int(random(0,256)));
    x = width;
    y = int(random(textAscent(),
            height-textDescent()));
    msgId = int(random(msgs.length));
  }
  fill(c);
  text(msgs[msgId],x,y);
}
