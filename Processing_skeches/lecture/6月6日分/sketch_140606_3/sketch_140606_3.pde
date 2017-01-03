int ix = 0;
int iy = 0;
int x = 20;
int y = 20;
int len;
int mode;

void setup(){
  size(400,400);
  smooth();
  len = 20;
  mode = 0;
}

void draw(){
  background(255);
  if(mode == 0)ix++;
  if(mode == 1)iy++;
  int g,t;
  
  for(g = 0; g < ix; g++){
    rect(x+g*10,10,10,10);
    if(x+g*10 >= width-len) mode = 1;
  }
  for(t = 0; t < iy; t++){
    rect(x+g*10-10,y+t*10,10,10);
  }
  println(ix);
}
