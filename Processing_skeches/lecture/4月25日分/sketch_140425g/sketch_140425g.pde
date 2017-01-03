void setup(){
  size(400,400);
}
void draw(){
  background(255,255,255);
  stroke(0);
  line(width/2,0,mouseX,mouseY);
  line(0,height,mouseX,mouseY);
  line(width,height,mouseX,mouseY);
 }
