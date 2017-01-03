size(400,400);
background(255);
for(int i=0;i<10;i++){
  fill(255-i*25);
  rect(10+i*20,20+i*5,width-(10+i*20)*2,height-(20+i*5)*2);
}
