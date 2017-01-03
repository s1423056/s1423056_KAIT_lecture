int rad = 50;
int e_x = 400;
int e_y = 600 + rad;
int dy = 2;


void setup(){
  size(800,600);
}


void draw(){
  background(0);
  e_y = e_y - dy;
  fill(255);
  ellipse(e_x,e_y,rad,rad);
}

