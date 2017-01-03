void setup(){
  size(400,400);
}

void draw(){
  for(int i = 1;i<=40;i++){
    
    if(mouseX > i*10-10 && mouseX < i*10 && i%3 == 0){
      fill(255,0,0);
    }
    if(mouseX > i*10-10 && mouseX < i*10 && i%5 == 0){
      fill(0,255,0);
    }
    if(mouseX > i*10-10 && mouseX < i*10 && i%15 == 0){
      fill(0,0,255);
    }
    rect(i*10-10,0,10,height);
    fill(255);
  }
}
