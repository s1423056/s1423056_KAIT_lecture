void setup(){
  size(400,400);
  smooth();
}

void draw(){
  background(255);
  for(int i = 0; i<4;i++){
    drawAlien(i*80+80,height/2);
  }

}

void drawAlien(int x, int y){
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
  int y2 = y+60;
  line(x2,y1,x-20,y2);
  line(x1,y1,x+20,y2);
  y1 = y+20;
  y2 = y+15;
  line(x2,y1,x-25,y2);
  line(x1,y1,x+25,y2);
  
}
