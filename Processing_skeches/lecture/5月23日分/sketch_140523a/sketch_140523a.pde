void setup(){
  size(400,400);
}

void draw(){
  background(255);
  for(int i = 0;i<40;i++){
    rect(mouseX-20*i,mouseY,20,20);
  }
}
