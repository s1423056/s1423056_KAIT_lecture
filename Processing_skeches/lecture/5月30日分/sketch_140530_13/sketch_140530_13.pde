String str = "Spring";
float x,y,d;
void setup(){
  size(300,100);
  textSize(32);
  x = 0;
  y = height/2;
  fill(0);
  rectMode(CENTER);
  d = 3;
}

void draw(){
  background(255);
  text(str,x,y);
  x = x + d;
  if(x+textWidth(str)>width){
    d = -3;
  }else if(x<=0){
    d = 3;
  }
}
