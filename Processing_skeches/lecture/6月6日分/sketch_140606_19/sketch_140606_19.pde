float theta;
float theta2;
  void setup(){
  size(400,400);
  smooth();
  theta = 0;
  theta2 = 180;
}
void draw(){

  background(255);
  translate( width/2 , height/2 );
  stroke(255,10,10);
  fill(255,10,10);
  ellipse(0,0,40,40);
  
  theta++;
  rotate(radians( theta ));
  translate( 100 ,0);
  stroke(10,255,10);
  fill(10,255,10);
  ellipse(0,0,20,20);
  
  theta2 += 3;
  rotate(radians(theta2));
  translate(50,0);
  fill(10,10,255);
  
  ellipse(0,0,15,15);
}
