int xCircle;
int yCircle;
int colorCircle;
int radiusCircle;

void setup(){
  size(400,400);
  smooth();
  xCircle = width / 2;
  yCircle = height / 2;
  colorCircle = 0;
  radiusCircle = width/3;
}

void draw(){
  background(255,255,255);
  stroke(255,255,255);
  fill(colorCircle, colorCircle, colorCircle);
  ellipse(xCircle,yCircle,radiusCircle*2,radiusCircle*2);
  colorCircle = colorCircle + 2;
}
