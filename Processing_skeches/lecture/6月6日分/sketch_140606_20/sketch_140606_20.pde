void setup() {
size(400, 400);
smooth();
}
void draw() {
background(255);
stroke(0);
translate(mouseX, mouseY);
foo(20,color(0,0,0));
foo(10,color(0,0,255));
foo(2,color(0,255,0));
}

void foo(int w,color c){
  pushMatrix();
  for(int i = 0; i<5; i++){
    stroke(c);
    strokeWeight(w);
    line(0,0,200,0);
    translate(200,0);
    rotate(radians(180-36));
  }
  popMatrix();
}
