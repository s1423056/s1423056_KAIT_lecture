String str = "Watanabe";
float s = 0;
void setup(){
  size(400,400);
  textSize(32);
  fill(0);
}

void draw(){
  background(255);
  for(float i = 0; i < 5; i = i+1 ){
    text(str,mouseX+textWidth(str)*i,mouseY);
   }
}

