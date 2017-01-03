PImage img;
int x,y,s;

void setup(){
  size(400,200);
  img = loadImage("c.png");
  x = width/2;
  y = height/2-50;
  s = 1;
}

void draw(){
  background(255);
  image(img,x,y,100,100);
  x += s;
  if(x+100 >= width)s = -1;
  if(x <= 0) s = 1;
}
