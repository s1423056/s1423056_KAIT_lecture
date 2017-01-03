String str = "Watanabe Syou";
void setup(){
  size(400,400);
  textSize(50);
  textAlign(CENTER);
  fill(0);
}

void draw(){
  background(255);
  if(mouseY>height/2){
    textSize(50);
  }else{
    textSize(20);
  }
  text(str,width/2,height/2);
}
