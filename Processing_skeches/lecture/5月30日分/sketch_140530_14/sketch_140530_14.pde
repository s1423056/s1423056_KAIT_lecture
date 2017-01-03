String str = "Watanabe Syou";

void setup(){
  size(360,360);
  textSize(16);
  fill(0);
  
}

void draw(){
  float r = mouseX/2;
  translate(width/2,height/2);
  background(255);
  rotate(-radians(r));
  text(str,0,0);
  println(r);
}
