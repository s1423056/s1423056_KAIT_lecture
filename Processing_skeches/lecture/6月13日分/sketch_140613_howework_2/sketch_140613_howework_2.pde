float rot;

void setup() {
  size(400, 400);
  smooth();
  rot = 0;
}

void drawLeftEye(float x,float y){
  noStroke();
  fill(255);
  ellipse(x-3.5,y,35,35);
  fill(0);
  ellipse(x,y,8,8);
}

void drawRightEye(float x,float y){
  noStroke();
  fill(255);
  ellipse(x+3.5,y,35,35);
  fill(0);
  ellipse(x,y,8,8);
}

void drawOwl(float x,float y){
  pushMatrix();
  translate(x-110,y-59);
  stroke(0);
  fill(0);
  ellipse(110, 45, 70, 70);
  ellipse(110, 70, 70, 70);
  rect( 75, 45, 70, 30);
  noStroke();
  fill(255);
  arc(110,45, 70, 70, 0, PI);
  drawLeftEye(96,45);
  drawRightEye(124,45);
  quad(110, 52, 114, 59, 110, 66, 106, 59);
  popMatrix();
}

void draw() {
  background(230);
  translate( width/2 , height/2 );
  rotate( radians(rot) );
  drawOwl(0,0);
}

void mouseClicked(){
  rot = rot + 90 ;
}
