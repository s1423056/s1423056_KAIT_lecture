size(400,400);
background(255);

for(int i = 0;i < 300;i++){
  stroke(random(255),random(255),random(255));
  float x = random(width);
  line(x,0,x,height);
}
