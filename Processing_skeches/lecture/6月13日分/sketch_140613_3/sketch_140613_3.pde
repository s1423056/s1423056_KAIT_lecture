PFont font;
String msg;
boolean displaying = false;
void setup(){
size(400,400);
smooth();
font = loadFont( "HGPMinchoB-48.vlw" );
  textFont(font,48);
  textAlign(CENTER);
}
void draw(){
  background(255);
  fill(0);
  if(displaying){
    text(msg,width/2,height/2);
    displaying = false;
  }
}
void mouseMoved(){
  displaying = true ;
  msg = "Moving..." ;
}
void mouseDragged(){
  displaying = true ;
  msg = "Dragging..." ;
}
