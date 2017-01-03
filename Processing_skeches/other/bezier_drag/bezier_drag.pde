int x1,x2,x3,x4;
int y1,y2,y3,y4;
float circlesize = 10;

void setup(){
  size(400,400);
  x1 = 10;
  x2 = 50;
  x3 = 100;
  x4 = 150;
  y1 = 10;
  y2 = 100;
  y3 = 200;
  y4 = 250;
}

void draw(){
  background(255);
  noFill();
  stroke(0);
  strokeWeight(1);
  bezier(x1,y1,x2,y2,x3,y3,x4,y4);
  stroke(128,128,0);
  strokeWeight(0.5);
  line(x1,y1,x2,y2);
  line(x3,y3,x4,y4);
  
  fill(0);
  text("x1:"+x1,300,300);
  text("y1:"+y1,350,300);
  text("x2:"+x2,300,320);
  text("y2:"+y2,350,320);
  text("x3:"+x3,300,340);
  text("y3:"+y3,350,340);
  text("x4:"+x4,300,360);
  text("y4:"+y4,350,360);
  
  noStroke();
  fill(255,0,0);
  ellipse(x1,y1,circlesize,circlesize);
  fill(0,128,255);
  ellipse(x2,y2,circlesize,circlesize);
  fill(0,128,255);
  ellipse(x3,y3,circlesize,circlesize);
  fill(255,0,0);
  ellipse(x4,y4,circlesize,circlesize);
}

boolean collision(int x_1, int y_1){
  int X = x_1 - mouseX;
  int Y = y_1 - mouseY;
  if(X*X+Y*Y < (circlesize/2)*(circlesize/2)) return true;
  else return false;
}

void mouseDragged(){
  boolean active = false;
  
  if(collision(x1,y1)){
    active = true;
    x1 = mouseX;
    y1 = mouseY;
  }
  
  if(collision(x2,y2) && !active){
    active = true;
    x2 = mouseX;
    y2 = mouseY;
  }
  
  if(collision(x3,y3) && !active){
    active = true;
    x3 = mouseX;
    y3 = mouseY;
  }
  
  if(collision(x4,y4) && !active){
    active = true;
    x4 = mouseX;
    y4 = mouseY;
  }
}

