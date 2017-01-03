float col = 0;
float r = 5;
float i = 0;

void setup(){
  rectMode(CENTER);
  size(800,800);
  colorMode(HSB,360,100,100);
  noStroke();

}

void draw(){
  background(0,0,99);
  translate(width/2,height/2);
  Drawellipse();
  
  rotate(radians(r));
  C();
  r = r+1 ;
}

void C(){
  col = 0;
  float c = 30+r;
  while(col<360){
    rotate(radians(30));
    translate(150,0);
    rotate(radians(-c));
    fill(col,99,99);
    noStroke();
    rect(0,0,20,20);
    col = col + 30;
    rotate(radians(c));
    translate(-150,0);
    c += 30;
  }
}

void Drawellipse(){
  stroke(0,0,0);
  noFill();
  ellipse(0,0,300,300);
}
