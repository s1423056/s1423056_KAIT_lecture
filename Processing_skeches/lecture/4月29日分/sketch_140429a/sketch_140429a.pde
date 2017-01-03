
int w = 30;

void setup(){
  size(400,400);
}

void draw(){
  background(255);
  noStroke();
  if(mousePressed == true){
    fill(100);
    rect(0,185,width,w);
  }else{
    fill(0);
    rect(185,0,w,height);
  }
}
