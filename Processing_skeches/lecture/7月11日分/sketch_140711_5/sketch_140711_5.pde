PFont font;
String msg = "Makise Riho";
int last;
int interval = 500;
int startTime;

void setup(){
  size(400,200);
  font = loadFont("Serif.plain-48.vlw");
  textFont(font,36);
  textAlign(CENTER,CENTER);
  last = 0;
  startTime = millis();
}

void draw(){
  background(255);
  fill(0);
  if((millis()-startTime) > interval){
    last = (last+1) % (msg.length()+1);
    startTime = millis();
  }
  text(msg.substring(0,last),0,0,width,height);
}


