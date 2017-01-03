int x,y,d,r;
boolean f1,f2;

void setup(){
  size(400,400);
  fill(100);
  d = 10;
  r = 20;
  x = r/2;
  y = r/2;
  f1 = true;
  f2 = false;
}

void draw(){
  background(255);
  ellipse(x,y,r,r);
  if(f1){
    y = y + d;
    if(y >= height - r/2){
      d = 10;
      f1 = false;
      f2 = true;
    }else if(y <= r/2){
      d = -10;
      f1 = false;
      f2 = true;
    }
  }
  if(f2){
    x = x + d;
    if(x >= width - r/2){
      d = -10;
      f2 = false;
      f1 = true;
    }else if(x <= r/2){
      d = 10;
      f1 = true;
      f2 = false;
    }
  }
}
