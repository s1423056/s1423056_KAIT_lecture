float col = 0;
int r = 0;
void setup(){
  rectMode(CENTER);
  size(400,400);
  colorMode(HSB,360,100,100);
  noStroke();

}

void draw(){
  background(0,0,99);
  translate(width/2,height/2);
  rotate(radians(r));
  
  C();
  
  r = r + 1;
}

void C(){
    col = 0;
    while(col<360){
    rotate(radians(10));
    fill(col,99,99);
    rect(150,0,20,20);
    col = col + 10;
  }
}
