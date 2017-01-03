float pos_x,pos_y;
float bx,by,br;
boolean bf;

void setup(){
  size(400,400);
  pos_x = width/2;
  pos_y = height/2;
  bx = 0;
  by = 0;
  br = 10;
  bf = false;
}

void draw(){
  background(0);
  noStroke();
  fill(10,10,255);
  if(keyPressed){
    if(keyCode == UP)pos_y -= 2;
    if(keyCode == LEFT)pos_x -= 2;
    if(keyCode == DOWN)pos_y += 2;
    if(keyCode == RIGHT)pos_x += 2;
  }
  triangle( pos_x,pos_y-20,pos_x-14,pos_y+20,pos_x+14,pos_y+20);
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

