int radiusCircle;
int xCircle;
int yCircle;

void setup(){
  size(400,400);
  smooth();
  radiusCircle = 0;
  xCircle = width / 2;
  yCircle = height / 2;
}
void draw(){
  background(255,255,255);
  fill(50,50,50);
  ellipse(xCircle,yCircle,radiusCircle*2,radiusCircle*2);
  radiusCircle = radiusCircle + 2;
}
