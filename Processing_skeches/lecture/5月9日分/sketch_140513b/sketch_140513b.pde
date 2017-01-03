int r;
int c;

void setup(){
  size(400,400);
  r = 0;
  noStroke();
}

void draw(){
  background(255);
  fill(c);
  ellipse(width/2,height/2,r,r);
  if(mousePressed){
    r++;
    c++;
  }
}
