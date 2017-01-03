int c = 0;
int d = 100;
float theta;
  void setup(){
  size(400,400);
  smooth();
  theta = 0;
}
void draw(){
  int a = width/2;
  int b = height/2;
  c += 2;
  background(255);
  translate( (a) , (b) );
  stroke(255,10,10);
  fill(255,10,10);
  ellipse(0,0,40,40);
  theta = theta + 1;
  rotate(radians( (c) ));
  translate( (d) ,0);
  stroke(10,255,10);
  fill(10,255,10);
  ellipse(0,0,20,20);
}
