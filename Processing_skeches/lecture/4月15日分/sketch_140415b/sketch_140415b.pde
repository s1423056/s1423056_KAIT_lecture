int window_w = 400;
int window_h = 300;
  
void setup(){
  size(window_w,window_h);
  background(255);//background(255,255,255);
}

void draw(){
  noStroke();
  fill(0,0,255);
  rect(0,0,window_w/3,window_h);
  fill(255,0,0);
  rect(window_w/3*2,0,window_w,window_h);
}
