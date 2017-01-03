  int window_w = 640;
  int window_h = 400;
  int rect_w = 601;
  int rect_h = 301;
  int rad = 200;

void setup(){
  size(window_w,window_h);
  background(100);
}

void draw(){
  fill(255);
  rect((window_w-rect_w)/2,(window_h-rect_h)/2,rect_w,rect_h);
  fill(255,0,0);
  noStroke();
  ellipse(window_w/2,window_h/2,rad,rad);
}
