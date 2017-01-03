float x;
float y;
float r;
int c;
int count;

float bx,by,br;
boolean bf;

void setup(){
  size(400,400);
  y = -20;
  x = 200;
  r = 20;
  c = 0;
  bx = 0;
  by = 0;
  br = 10;
  bf = false;
  count = 0;
}

void draw(){
  background(0);
  noStroke();
  fill(10,10,255);
  triangle( mouseX,mouseY-20,mouseX-14,mouseY+20,mouseX+14,mouseY+20);
  fill(255,0,0);
  ellipse(x,y,r,r);
  y++;
  if(bf){
    fill(255,255,0);
    ellipse(bx,by,br,br);
    by-=3;
    if(by < -br*2) bf = false;
  }
  collision();
  fill(255);
  textSize(20);
  text("score:" + count,20,20);
  println(count);
}

void mouseClicked(){
  if(bf == false){
    bx = mouseX;
    by = mouseY;
    bf = true;
  }
}

void collision(){
  if( ((y-by)*(y-by) + (x-bx)*(x-bx)) < ((r+br)*(r+br))  ){
    y = -50;
    x = random(50,width-50);
    r = random(20,40);
    bf = false;
    count++;
  }
}
