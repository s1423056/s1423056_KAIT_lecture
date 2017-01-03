float xRect,yRect;
float wRect,hRect;
float xE,yE,rE;
color cRect;
boolean flag,game;
int count,s_count,score;

void setupRect(){
  wRect = random(20,60);
  hRect = random(20,60);
  xRect = random(width-wRect);
  yRect = random(height-hRect);
  cRect = color(random(360),99,99);
  flag = true;
}

void setupEllipse(){
  rE = random(20,60);
  xE = random(width-rE);
  yE = random(height-rE);
  cRect = color(random(360),99,99);
  flag = false;
}

void setupgraph(){
  count = 0;
  int t = int(random(0,2));
  if(t == 0){
    setupRect();
  }else{
    setupEllipse();
  }
}

void drawgraph(){
 if(flag){
    stroke(cRect);
    fill(cRect);
    rect(xRect,yRect,wRect,hRect);
 }else{
    stroke(cRect);
    fill(cRect);
    ellipse(xE,yE,rE,rE);
 }
}

void setup(){
  s_count = 3;
  score = 0;
  size(400,400);
  colorMode(HSB,359,99,99);
  int t = int(random(0,2));
  game = true;
  if(t == 0){
    setupRect();
  }else{
    setupEllipse();
  }
}

void draw(){
  background(0,0,99);
  if(game){
    textAlign(CENTER);
    textSize(20);
    drawgraph();
    fill(0);
    text(s_count,width/2,height/8);
    text(120-count,width-30,height-5);
    
    count++;
    if(count >= 120) {
      setupgraph();
      s_count--;
    }
    if(s_count <= 0){
      game = false;
    }
  }else{
    fill(0);
    textAlign(CENTER);
    text("END    " + "Score : "+ score, width/2,height/2);
  }
}

boolean between( float x, float a, float b){
  if( x >= a && x <= b ){
    return true;
  }else{
    return false;
  }
}

boolean inRect(float x,float y,
  float rx,float ry,float w,float h){
  if(between(x,rx,rx+w) && between(y, ry ,ry+h)){
    return true;
  }else{
    return false;
  }
}

boolean inEllipse(){
  if((mouseX-xE)*(mouseX-xE)+(mouseY-yE)*(mouseY-yE) < rE*rE){
    return true;
  }else{
    return false;
  }
}

void mouseClicked(){
  if(inRect(mouseX,mouseY,xRect,yRect,wRect,hRect)){
    setupgraph();
    score++;
  }
  if(inEllipse()){
    setupgraph();
    score++;
  }
}

