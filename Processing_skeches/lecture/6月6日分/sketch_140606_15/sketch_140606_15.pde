int ih,im,is;
void drawLeftEye(float x,float y){
  noStroke();
  fill(255);
  ellipse(x,y,35,35);
  if(second()%4 == 2||second()%4 == 3){
    stroke(0);
    line(x+3.5,y,x+8,y);
  }else{
    fill(0);
    ellipse(x+3.5,y,8,8);
  }
}

void drawRightEye(float x,float y){
  noStroke();
  fill( 255 );
  ellipse(x, y, 35, 35);

  if(second()%4 == 1||second()%4 == 3){
    stroke(0);
    line(x-3.5,y,x-8,y);
  }else{
    fill( 0 );
    ellipse(x-3.5, y, 8, 8);
  }
}

void drawOwl(float x,float y){
pushMatrix();
stroke(0);
fill(0);
ellipse(x,y-14,70,70);
ellipse(x,y+11,70,70);
rect(x-35,y-14,70,30);
noStroke();
fill(255);
arc(x,y-14,70,70,0,PI);
  drawLeftEye(x-17.5,y-14);
  drawRightEye(x+17.5,y-14);
  fill(0);
  noStroke();
  quad(x,y-7, x+4,y, x,y+7, x-4,y);
popMatrix();
}

void setup() {
  size(400, 400);
  smooth();
}

void draw() {
  ih = hour();
  im = minute();
  is = second();


  background(230);
    textSize(20);
  fill(0);
  text(ih,50,50);
  text(im,100,50);
  text(is,150,50);
  drawOwl(mouseX,mouseY);
}
