size(400,400);
smooth();
background(255);
for(int x=0;x<20;x++){
  for(int y=0;y<20;y++){
    fill(y*12);
    ellipse(10+20*x,10+20*y,15,15);
  }
}
