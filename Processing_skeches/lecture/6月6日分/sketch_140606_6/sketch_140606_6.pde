//drawing left eyes
  void drawLeftEye(float x,float y){
  noStroke();
  fill(255);
  ellipse(x-3.5,y,35,35);
  fill(0);
  ellipse(x,y,8,8);
}

//drawing right eyes
void drawRightEye(float x,float y){
  noStroke();
  fill(255);
  ellipse(x+3.5,y,35,35);
  fill(0);
  ellipse(x,y,8,8);
}

void setup() {
  size(200, 200);
  smooth();
}

void draw() {
  background(230);
  //drawing body
  stroke(0);
  fill(0);
  ellipse(110, 45, 70, 70);
  ellipse(110, 70, 70, 70);
  rect( 75, 45, 70, 30);
  noStroke();
  fill(255);
  arc(110,45, 70, 70, 0, PI); // あご
  // 左目
  drawLeftEye(96,45);
  // 右目
  drawRightEye(124,45);
  quad(110, 52, 114, 59, 110, 66, 106, 59); // くちばし
}
