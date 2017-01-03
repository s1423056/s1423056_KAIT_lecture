float x;
float y;
float r;
int c;

void setup(){
  size(400,400);
  y = -20;
  x = 200;
  r = 20;
  c = 0;
}

void draw(){
  background(0);
  noStroke();
  fill(10,10,255);
  triangle( mouseX,mouseY-20,mouseX-14,mouseY+20,mouseX+14,mouseY+20);
  fill(255,0,0);
  ellipse(x,y,r,r);
  y++;
  if(mousePressed){
    stroke(255,255,0);
    line(mouseX,mouseY-20,mouseX,0);
    if(mouseX <= x + r/2 && mouseX >= x - r/2){
      y = -50;
      x = random(50,width-50);
      r = random(10,30);
      c++;
    }
  }
  println(c);
}
