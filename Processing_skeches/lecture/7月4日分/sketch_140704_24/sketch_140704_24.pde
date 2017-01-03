Rect r[] = new Rect[100];

void setup(){
  size(400,400);
  smooth();
  noStroke();
  for(int i = 0;i<100;i++){
    r[i] = new Rect();
  }
  for(int t = 0; t < 100; t++){
    for(int h = 1; h < 100; h++){
      if(r[t].s < r[h].s){
        Rect tmp = r[h];
        r[h] = r[t];
        r[t] = tmp;
      }
    }
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
  color c;
  int s;
  
  Rect(){
    x = random(0,width);
    y = random(0,height);
    rot = random(0,TWO_PI);
    s = int(random(20,50));
    c = color(int(random(0,256)),int(random(0,256)),int(random(0,256)));
    v = 0.05*s;
  }
  
  void Move(){
   rot = rot + PI/90;
   y = y+v;
   if(y-30>height){
     y = -30;
   }
  }
  
  void Draw(){
   fill(c);
   pushMatrix();
   translate(x,y);
   rotate(rot);
   rectMode(CENTER);
   rect(0,0,s,s);
   popMatrix();
  }
}




