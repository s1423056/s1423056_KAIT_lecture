float bx,by,br;
boolean bf;

void setup(){
  size(400,400);
  bx = 0;
  by = 0;
  br = 10;
  bf = false;
}

void draw(){
  background(0);
  noStroke();
  fill(10,10,255);
  
  triangle(mouseX,mouseY-20,mouseX-14,mouseY+20,mouseX+14,mouseY+20);
  if(bf){
    fill(255,255,0);
    ellipse(bx,by,br,br);
    by-=3;
    if(by < -br*2) bf = false;
  }
}

void mouseClicked(){
  if(bf == false){
    bx = mouseX;
    by = mouseY;
    bf = true;
  }
}

