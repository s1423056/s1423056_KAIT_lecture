boolean keyState[];
boolean p_keyState[];
character c;

void setup(){
  size(600,400);
  keyState = new boolean[256];
  p_keyState = new boolean[256];
  for(int t = 0;t<keyState.length;t++){
    keyState[t] = false;
    p_keyState[t] = false;
  }
  c = new character();
}

void draw(){
  background(255);
  c.update();
  c.draw();
  for(int i=0;i<keyState.length;i++){
    p_keyState[i] = keyState[i];
  }
}

void keyPressed(){
  if(0<=key && key<256){
    keyState[key] = true;
  }else if(0<=keyCode && keyCode<256){
    keyState[keyCode] = true;
  }    
}

void keyReleased(){
  if(0<=key && key<256){
    keyState[key] = false;
  }else if(0<=keyCode && keyCode<256){
    keyState[keyCode] = false;
  }
}
