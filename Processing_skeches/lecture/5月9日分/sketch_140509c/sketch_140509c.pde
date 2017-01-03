int x;
void setup(){
  size(400,200);
  x = 0;//initialize
}

void draw(){
  background(255);
  stroke(0);
  line(x,0,x,height);
  x = x+1;
  if(x >= width){
    x = 0;
  }
}
