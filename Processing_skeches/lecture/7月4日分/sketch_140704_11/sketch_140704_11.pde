Rect r[] = new Rect[100];
void setup(){
  size(400,400);
  smooth();
  for(int i = 0;i<100;i++){
    r[i] = new Rect();
  }
}
void draw(){
  background(255);
  for(int i = 0;i<100;i++){
    r[i].Move();
    r[i].Draw();
  }
}

class Rect{
  float x,y;
  float rot;
  float v;
  
  Rect(){
    x = random(0,width);
    y = random(0,height);
    v = random(1.0,1.5);
    rot = random(0,PI);
  }
  void Move(){
   rot = rot + PI/90;
   y = y+v;
   if(y-30>height){
     y = -30;
   }
  }
  
  void Draw(){
   stroke(255,25,50);
   fill(255,25,50);
   pushMatrix();
   translate(x,y);
   rotate(rot);
   rectMode(CENTER);
   rect(0,0,20,20);
   popMatrix();
  }
}








