void setup(){
  size(400,400);
  
}

void draw(){
  background(0);
  noStroke();
  fill(10,10,255);
  triangle( mouseX,mouseY-20,mouseX-14,mouseY+20,mouseX+14,mouseY+20);
  if(mousePressed){
    stroke(255,255,0);
    line(mouseX,mouseY-20,mouseX,0);
  }
}
