size(400,400);
background(255);
stroke(255);
strokeWeight(4);

int roundsize = 90;

for(int i = 4;i >= 0;i = i-1){
  switch(i){
    case 1:
      fill(255,255,0);
      break;
    case 2:
      fill(255,0,0);
      break;
    case 3:
      fill(0,30,255);
      break;
    case 4:
      fill(0);
      break;
  }
  ellipse(199,199,roundsize*i,roundsize*i);
  
}
