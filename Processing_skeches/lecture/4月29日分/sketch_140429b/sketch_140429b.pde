int x;

void setup(){
  background(255);
  size(400,200);
  x = width;
}

void draw(){
  background(255);
  line(x,0,x,height);
  x = x - 1;
}
