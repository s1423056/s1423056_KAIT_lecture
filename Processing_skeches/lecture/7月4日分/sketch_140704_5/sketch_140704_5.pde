float y;
float rot;
float v;
 
void setup(){
  size(400,400);
  smooth();
  y = 0;
  rot = 0;
  v = random(0.5,1.5);
}

void draw(){
  background(255);
  stroke(255,25,50);
  fill(255,25,50);
  rot = rot+PI/90;
  y = y+v;
  if(y>height){
    v = random(1.0,1.5);
    y = 0;
  }
  pushMatrix();
  translate(width/2,y);
  rotate(rot);
  rectMode(CENTER);
  rect(0,0,20,20);
  popMatrix();
}
