float y;
float rot;

void setup(){
  size(400,400);
  smooth();
  y = 0;
  rot = 0;
}

void draw(){
  background(255);
  stroke(255,25,50);
  fill(255,25,50);
  y = y+1;
  rot = rot+PI/90;
  pushMatrix();
  translate( width/2 , y );
  rotate( rot );
  rectMode( CENTER );
  rect(0,0,20,20);
  popMatrix();
}
