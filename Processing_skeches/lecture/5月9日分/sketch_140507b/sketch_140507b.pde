int x,y,r,c;
void setup(){
  size(400,400);
  noStroke();
  x = width/2;
  y = height/2;
  r = 1;
  c = 0;
}

void draw(){
  background(255);
  fill(c);
  ellipse(x,y,r,r);
  c = c + 1;
  r = r + 1;
}
