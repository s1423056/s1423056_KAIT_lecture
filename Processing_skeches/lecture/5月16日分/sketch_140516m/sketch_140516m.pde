float rad;
void setup(){
  size(400,400);
  noFill();
  rad = 20;
}

void draw(){
  background(255);
  line(mouseX,0,mouseX,height);
  line(0,mouseY,width,mouseY);
  ellipse(mouseX,mouseY,rad,rad);
  ellipse(mouseX,mouseY,rad*2,rad*2);
  if(mousePressed){
    rad = 60;
  }
  if(rad > 20){
    rad -= 0.1;
  }
}
