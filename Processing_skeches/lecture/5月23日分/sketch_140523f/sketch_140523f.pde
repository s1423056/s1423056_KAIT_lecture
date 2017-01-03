size(400,400);
background(255);
noStroke();
int t = 400/16;
for(int x = 0;x<8;x++){
  for(int y = 0;y<8;y++){
    fill(255,10-y,200-(200/8*y));
    rect(t+t*x*2,t*y*2,t,t);
    rect(t*x+t*x,t+t*y+t*y,t,t);
  }
}
