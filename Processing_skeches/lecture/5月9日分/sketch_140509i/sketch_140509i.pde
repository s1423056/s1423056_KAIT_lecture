int y;
int r=15;

void setup(){
  size(400,400);
  smooth();
}

void draw(){
  background(255);
  fill(200);
  y = mouseY;
  if(mouseY<r/2){
    y = r/2;
  }else if(mouseY > height - r/2){
    y = height - r/2;
  }
  ellipse(width/2,y,r,r);
}

