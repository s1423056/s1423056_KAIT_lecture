void drawLeftEye(float x,float y){
  fill(255);
  ellipse(x+2.5,y,35,35);
  fill(0);
  ellipse(x+6,y,8,8);
}

void drawRightEye(float x,float y){
  fill( 255 );
  ellipse(x+7.5, y, 35, 35);
  fill( 0 );
  ellipse(x+4, y, 8, 8);
}

void drawOwl(){
  stroke(0);
  fill(0);
  ellipse(110,45,70,70);
  ellipse(110,70,70,70);
  rect(75,45,70,30);
  noStroke();
  fill(255);
  arc( 110 , 45 ,70, 70, 0, PI);
  drawLeftEye(90,45);
  drawRightEye(120,45);
  fill(0);
  quad(110, 52, 114, 59, 110, 66, 106, 59); 
}

void setup() {
size(200, 200);
smooth();
}

void draw() {
background(230);
drawOwl();
}
