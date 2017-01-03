float[] tops;

void setup(){
  size(400,300);
  tops = new float[20];
  for(int i=0;i<tops.length ;i++){
    tops[i] = random(height);
  }
}
void draw(){
  background(255);
  stroke(0);
  fill(127);
  for(int i=0;i<tops.length ;i++){
    rect(20*i+2,tops[i],16,height);
  }
}
boolean inRect(float x,float y,float xTopLeft,float yTopLeft,float w,float h){
  if(( xTopLeft <= x && x <= xTopLeft+w ) && ( yTopLeft <= y && y <= yTopLeft+h )){
    return true;
  }else{
    return false;
  }
}

void mouseClicked(){
  for(int i=0;i<tops.length;i++){
    if(inRect(mouseX,mouseY,20*i+2,tops[i],16,height)){
      int last = tops.length - 1;
      float tmp = tops[i];
      tops[i] = tops[last];
      tops[last] = tmp ;
      break;
    }
  }
}
