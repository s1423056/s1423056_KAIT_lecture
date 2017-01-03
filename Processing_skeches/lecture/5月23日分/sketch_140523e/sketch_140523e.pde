void setup(){
  size(400,400);
  fill(100);
  rectMode(CENTER);
}

void draw(){
  background(255);
  
  stroke(0);
  for(int i = 0;i<7;i++){
    line(mouseX+30-10*i,mouseY-20,mouseX+30-10*i,mouseY+20);
  }
  noStroke();
  rect(mouseX,mouseY,75,30);
}
