void setup(){
  size(360,360);
  noStroke();
  colorMode(HSB,359,99,99);
}

void draw(){
  background(359);
  fill(mouseX,99,99);
  ellipse(mouseX,mouseY,20,20);
}
