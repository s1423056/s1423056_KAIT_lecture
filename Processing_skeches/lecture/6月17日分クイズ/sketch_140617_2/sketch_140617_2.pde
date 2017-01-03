String[] msg = {"Left","Middle","Right"}; 
color[] c = {color(255,10,10),
             color(10,255,10),
             color(10,10,255)};
PFont font;
void setup(){
  size(300,300);
  smooth();
  font = loadFont("Serif.plain-48.vlw");
  textFont(font ,36);
  textAlign(CENTER);
}

void draw(){
  background(255);
  for(int i = 0; i<3;i++){
     if(i*width/3 <= mouseX && mouseX < (i+1)*width/3){
       fill(c[i]);
       text(msg[i],width/2,height/2);
     } 
  } 
}
