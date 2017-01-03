int x,r;
boolean m;
void setup(){
  size(400,400);
  x = 0;
  r = 15;
  m = true;
  noStroke();
}
void draw(){
  background(255);
  for(int i = 0;i<5;i++){
    fill(i*10,i*10,i*10,i*50);
    if(m)ellipse(x+i*3,height/2,r,r);
    if(!m)ellipse(x-i*3,height/2,r,r);
  }
  if(x <= r)m = true;
  if(x >= width-r)m = false;
  if(m){
    x += 3;
  }else{
    x -= 3;
  }
  
}
