size(400,400);
noFill();

for(int i=0;i<30;i++){
  beginShape();
  float y = random(100,300);
  stroke(random(255),random(255),random(255));
  vertex(0,y);
  
  for(int x=0;x<40;x++){
    y = y + random(-10,10); 
    vertex(10*x,y); 
    
  }
  endShape();
}


