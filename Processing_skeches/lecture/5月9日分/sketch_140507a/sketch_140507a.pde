void setup(){
  size(400,400);
  noStroke();
}

void draw(){
  background(255);
  fill(0,255,0);
  rect(0,0,mouseX,mouseY);
  fill(255,0,0);
  rect(mouseX,mouseY,width,height);
}
