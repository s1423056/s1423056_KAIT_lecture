PFont font;
int maxTime;
int startTime;
int interval;
boolean pressing=false;

void setup(){
  
  size(400,400);
  maxTime = 0;
  smooth();
  font = createFont("HGSGothicM-48.vlw",48);
  textFont(font,24);
}

void draw(){
  background(255);
  fill(0);
  
  if(mousePressed){
    if(pressing == false){
      startTime = millis();
      pressing = true;
    }
  interval = millis()-startTime;
  text(interval,mouseX,mouseY);
  }else{
    pressing = false;
  }
  
  if(interval> maxTime){
    maxTime = interval;
  }
  text(maxTime,0,height-textDescent());
}
