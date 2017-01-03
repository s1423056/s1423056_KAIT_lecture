float theta;

void setup(){
  size(400,400);
  smooth();
  theta = 0;
}

void draw(){
  background(255);
  translate( width/2 , height/2 );
  stroke(255,10,10);
  fill(255,10,10);
  ellipse(0,0,40,40);
  theta = theta + 1;
  rotate(radians( theta ));
  translate( 100 ,0);
  stroke(10,255,10);
  fill(10,255,10);
  ellipse(0,0,20,20);
}
