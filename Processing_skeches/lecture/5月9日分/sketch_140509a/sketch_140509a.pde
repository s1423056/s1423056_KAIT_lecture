void setup(){
  size(400,400);
}

void draw(){
  background(255);
  fill(0);
  if(mouseY < height/2){
    rect(0,0,width,height/2);
  }else{
    rect(0,height/2,width,height);
  }
}
