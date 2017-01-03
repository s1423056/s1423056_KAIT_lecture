int e_x = 300;
int e_y = 600;
int dy = 5;
int l = 300;


void setup(){
  size(800,600);
}


void draw(){
  background(255);
  e_y = e_y - dy;
 
  
  line(e_x,e_y,e_x + l,e_y);
}
