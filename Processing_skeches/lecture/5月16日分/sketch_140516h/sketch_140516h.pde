size(600,600);
smooth();
noStroke();
rectMode(CENTER);
background(255);
for(int y = 0;y < 15;y++){
  for(int x = 0;x < 15;x++){
    fill(50 * ((x+y) % 5), 50 * ((x+y) % 5) ,100 );
    if((x+y) % 2 == 0){
      ellipse(40*x+20,40*y+20,30,30);
    }else{
      rect(40*x+20,40*y+20,30,30);
    }
  }
}
