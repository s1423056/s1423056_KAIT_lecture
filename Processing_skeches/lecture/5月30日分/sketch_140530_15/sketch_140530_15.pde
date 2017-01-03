size(400,400);
background(255);
rectMode(CENTER);
translate(width/2,height/2);
colorMode(HSB,360,100,100);
noStroke();
float rad = 0;


while(rad<360){
  
  rotate(radians(10));
  fill(rad,99,99);
  rect(150,0,20,20);
 
  rad = rad + 10;
}

