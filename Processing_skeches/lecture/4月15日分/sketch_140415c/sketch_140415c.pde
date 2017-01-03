int window_w = 400;
int window_h = 300;

void setup(){
  size(window_w,window_h);
  background(255);//backgrount(255,255,255);
}

void draw(){
  noStroke();
  fill(0);//fill(0,0,0);
  rect(0,0,window_w,window_h/3);
  fill(255,0,0);
  rect(0,window_h/3,window_w,window_h/3*2);
  fill(255,100,0);
  rect(0,window_h/3*2,window_w,window_h);
}
