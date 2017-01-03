void setup(){
  size(700,200);
  colorMode(HSB,359,99,99);
  smooth();
}
void draw(){
  fadeToWhite();
  color c = color (map(mouseX, 0 , width, 0 , 359),99,99);
  stroke(c);
  fill(c);
  float r = random( 10 , 30 );
  ellipse(mouseX,mouseY,2*r,2*r);
}
void fadeTo(color c){
  stroke(c,20);
  fill(c,20);
  rectMode(CORNER);
  rect( 0 , 0 , width , height );
}
void fadeToWhite(){
  fadeTo( color(0,0,99) );
}
