int x;

void setup(){
  size(300,300);
  x = 0;
}

void draw(){
  background(255);
    x++;
  if(x >= width){
    x = 0;
  }
  line(x,0,x,height);
}
