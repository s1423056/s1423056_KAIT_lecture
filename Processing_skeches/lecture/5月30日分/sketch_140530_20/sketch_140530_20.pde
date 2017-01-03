void setup(){
  size(400,400);
  smooth();
}
void draw(){
  background(255);
  translate(width/2,height/2);
  timer();
 
}

void timer(){
  float angle = -90+6*second();
  float angle2 = -90+6*minute();
  float angle3 = -90+6*hour();
  
  stroke(0);
    
  rotate(radians(angle3));
  fill(50);
  triangle(0,7,120,0,0,-7);
  
  rotate(radians(-angle3));
  rotate(radians(angle2));
  fill(150);
  triangle(0,5,200,0,0,-5);
    
  rotate(radians(-angle2));
  rotate(radians(angle));
  stroke(255,0,0);
  line(0,0,90,0);
  
  noStroke();
  fill(0);
  ellipse(0,0,20,20);
}
