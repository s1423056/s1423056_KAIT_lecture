int x,r;
float c1,c2,c3;
float c4,c5,c6;
boolean m;
void setup(){
  size(400,400);
  x = 0;
  r = 20;
  m = true;
  noStroke();
  c4 = 255;
  c5 = 255;
  c6 = 255;
}
void draw(){
  background(c4,c5,c6);
  ellipse(x,height/2,r,r);
  
  if(x <= r){
    m = true;
    colorchange();
    fill(c1,c2,c3);
  }
  if(x >= width-r){
    m = false;
    colorchange();
    fill(c1,c2,c3);
  }
  if(m){
    x += 3;
  }else{
    x -= 3;
  }
}

void colorchange(){
  c4 = c1;
  c5 = c2;
  c6 = c3;
  c1 = random(255);
  c2 = random(255);
  c3 = random(255);
}
