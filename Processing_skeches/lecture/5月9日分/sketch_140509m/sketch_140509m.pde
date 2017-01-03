int y;
int w;
int h;

void setup(){
  size(300,600);
  y = 30;
  w = 30;
  h = 60;
  fill(0);
}

void draw(){
  background(150);
  rect(width - w,y-h/2,w,h);
  y = mouseY;
  if(mouseY < h/2){
    y = h/2;
  }else if(mouseY > height - h/2){
    y = height - h/2;
  }
}
