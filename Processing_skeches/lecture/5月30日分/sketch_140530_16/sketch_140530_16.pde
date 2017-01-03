String str = "Watanabe";
float s; 
void setup(){
  size(600,400);
  s = width;
  textSize(32);
  fill(0);
}

void draw(){
  background(255);
  for(int i = 0; i<100;i++){
   text(str,s+i*textWidth(str),height/2);
  }
  s -= 3;
}

