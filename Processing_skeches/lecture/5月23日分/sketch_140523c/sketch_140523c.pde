size(400,400);
background(255);
float x = 0;
float y = height/2;
beginShape();
vertex(0,height/2);
for(int i=0;i<50;i++){
  x = x + random(5,20);
  y = y + random(-10,10);
  vertex(x,y);
}
endShape();
