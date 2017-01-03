int rect_y = 20;
int rect_s = 80;
int d = 40;

void setup(){
  size(660,640);
  background(0);
}



void draw(){
  background(0);
  for(int i = 0;i<=8;i++){
    fill(255);
    rect(0,d*i+d*i,width,d);
  }
  for(int i = 0;i<5;i++){
    if(i%2==1){
      fill(0,0,30);
    }else{
      fill(255,255,0);
    }
    rect(120*i+50,rect_y,rect_s,rect_s);
  }
  rect_y += 3;
}
