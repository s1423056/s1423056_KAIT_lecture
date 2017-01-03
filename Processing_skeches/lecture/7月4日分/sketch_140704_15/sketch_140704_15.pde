void crossPipe(float x,float y,float l){
  line (x+l/2,y,x+l/2,y+l);
  line (x,y+l/2,x+l,y+l/2);
}
void bendedPipe0(float x,float y,float l){
  arc(x,y,l,l,0,HALF_PI);
  arc (x+l,y+l,l,l, PI , PI+HALF_PI );
}

void bendedPipe1(float x,float y,float l){
  arc(x+l,y,l,l,HALF_PI,PI);
  arc (x,y+l,l,l, -HALF_PI , 0 );
}

void setup(){
  size(400,200);
  smooth();
}

void draw(){
  background(255);
  stroke(0);
  crossPipe(mouseX,mouseY,40);
  bendedPipe0(mouseX+1*40,mouseY,40);
  bendedPipe1(mouseX+2*40,mouseY,40);
}
