int rad = 50;
int e_x = 800 + rad;
int e_y = 300;
int dx = 2;


void setup(){
  size(800,600);
}


void draw(){
  background(0);
  e_x = e_x - dx;
  fill(255);
  ellipse(e_x,e_y,rad,rad);
}

