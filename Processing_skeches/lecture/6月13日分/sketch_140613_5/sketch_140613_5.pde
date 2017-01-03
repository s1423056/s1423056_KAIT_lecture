color fColor;
void setup(){
  size(400,400);
  rectMode(CENTER);
  colorMode(HSB,359,99,99);
  fColor = color(0,0,80);
}
void draw(){
  background(0,0,99);
  stroke( 0,0,0 );
  fill( fColor );
  rect(width/2,height/2,width/2,height/2);
}
void mousePressed(){
  fColor = color(random( 0,360 ),99,99);
}
void mouseReleased(){
  fColor = color( 0 , 0 , 50 );
}
