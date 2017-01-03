void setup(){
  size(400,400);
  noFill();
}

void draw(){
  if(mousePressed){
    stroke(255);
    background(0);
  }else{
    stroke(0);
    background(255);
  }
  
  line(0,mouseY,width,mouseY);
  line(mouseX,0,mouseX,height);
  ellipse(mouseX,mouseY,10,10);
  ellipse(mouseX,mouseY,20,20);
}
