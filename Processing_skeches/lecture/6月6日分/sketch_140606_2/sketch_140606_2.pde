void setup(){
  size(400,400);
  smooth();
}
void draw(){
  float x,y;
  background(255);
  noFill();
  stroke(0);
  x = mouseX;
  y = mouseY;
  float dx,dy;
  while(x < width && y < height){
    dx = random(10,20);
    dy = random(10,20);
    rect(x,y,dx,dy);
    x += dx;
    y += dy;
  }
}
