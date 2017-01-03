int xLeft = 100;
int yTop = 100;
int w = 200;
int h = 150;

void setup(){
  size(400,400);
}

void draw(){
  background(255);
  stroke(0);
  if(mouseX > xLeft && mouseX < xLeft+w && mouseY > yTop && mouseY < yTop + h && mousePressed == true){
    fill(255,128,32);
  }else{
    noFill();
 }
rect(xLeft,yTop,w,h);
}
