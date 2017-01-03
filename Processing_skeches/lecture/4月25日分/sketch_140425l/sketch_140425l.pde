int rad = 50;
int e_x = 600;
int e_y = 600;
int dx = 5;


void setup(){
  size(600,600);
}


void draw(){
  background(0);
  e_x = e_x - dx;
  e_y = e_y - dx;
  fill(255);
  ellipse(e_x,e_y,rad,rad);
}

