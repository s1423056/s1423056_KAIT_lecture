int x;
int r;
boolean f;

void setup(){
  size(400,400);
  x = width;
  r = 50;
  fill(0);
}

void draw(){
  background(255);
  ellipse(mouseX,mouseY,r,r);
  line(x,0,x,height);
  if(f){
    x--;
  }else{
    x++;
  }
  if(x < mouseX + r/2){
    x = mouseX + r/2;
  }
  if(x <= mouseX + r/2){
    f = false;
  }else if(x >= width){
    f = true;
  }
}
