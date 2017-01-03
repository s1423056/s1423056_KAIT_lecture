size(400,400);
smooth();
noStroke();
background(255);
for(int y = 0;y < 10;y++){
for(int x = 0;x < 10;x++){
fill( 50*((x+y)%5), 50*((x+y)%5) ,100 );
float r = random(20,30);
ellipse(40*x+20+ random(-5,5),
40*y+20+ random(-5,5),r,r);
}
}
