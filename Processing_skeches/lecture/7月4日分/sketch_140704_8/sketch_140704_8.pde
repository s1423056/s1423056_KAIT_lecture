void setup(){
  size(800,300);
  smooth();
}

void draw(){
  background(255);
  for(int i = 0;i<6;i++){
    int x = 100+150*i;
    drawAlien(x,height/2,2*i+1);
  }
  
}

void drawAlien(int x, int y,int hands){
  rectMode(CENTER);
  stroke(0);
  fill(150);
  rect(x,y,20,100);
  stroke(0);
  fill(255);
  int y3 = y - 30;
  ellipse(x,y3,60,60);
  fill(0);
  ellipse(x-19,y3,16,32);
  ellipse(x+19,y3,16,32);
  stroke(150);
  int x1 = x+10;
  int x2 = x-10;
  int y1 = y+50;
  float y2 = y+60;
  line(x2,y1,x-20,y2);
  line(x1,y1,x+20,y2);
  
  float[] yh;
  yh = new float[hands];
  y1 = y+10;

  for(int i = 0;i<hands;i++){
    yh[i] = y1+i*(40/hands);
    y2 = yh[i] - 5.0;
    line(x2,yh[i],x-25,y2);
    line(x1,yh[i],x+25,y2);
  }
}
