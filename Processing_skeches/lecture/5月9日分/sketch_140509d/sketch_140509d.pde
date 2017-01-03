float x;
float dx;
int side;

void setup(){
  size(400,200);
  x = 0;
  side = 50;
  dx = 0.5;
}

void draw(){
  background(255);
  stroke(255,10,10);
  fill(255,10,10);
  rect(x,0,side,height);
  x = x + dx;
  if(x < 0){
    x = 0;
    dx = 0.5;
  }else if((x + side) >= (width - 1)){
    x = (width - 1) - side;
  dx = -0.5;
  }
}
