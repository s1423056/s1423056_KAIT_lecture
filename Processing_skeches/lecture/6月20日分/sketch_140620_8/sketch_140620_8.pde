float[] tops;
int choiceId;

void setup(){
  size(400,300);
  tops = new float [20];
  for(int i=0;i<tops.length ;i++){
    tops[i] = random(height);
  }
  choiceId = -1 ;
}

void draw(){
  background(255);
  stroke(0);
  for(int i=0;i<tops.length ;i++){
    if(i == choiceId){
      fill( 255,0,0 );
    }else{
      fill( 100 );
    }
    rect(20*i+2,tops[i] ,16,height);
    }
}

boolean inRect(float x,float y,float xTopLeft,float yTopLeft,float w,float h){
  if(( xTopLeft <= x && x <= xTopLeft+w ) && ( yTopLeft <= y && y <= yTopLeft+h )){
    return true;
  }else{
    return false;
  }
}

void mousePressed(){
  choiceId = -1;
  for(int i=0;i< tops.length;i++){
    if(inRect(mouseX,mouseY,20*i+2,tops[i],16,height)){
      choiceId = i ;
      break;
    }
  }
}
void mouseReleased(){
  choiceId = -1;
}
