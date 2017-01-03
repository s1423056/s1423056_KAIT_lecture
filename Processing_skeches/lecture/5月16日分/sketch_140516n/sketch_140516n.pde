int x,y,r,s,w,mode;
void setup(){
  size(400,400);
  x = 10;
  y = 10;
  r = 20;
  s = 2;
  mode = 0;
  w = 0;
  noStroke();
  fill(random(255),random(255),random(255));
}

void draw(){
  background(255);
  
  switch(mode){
    case 0:{
      x+=s;
      if(x >= width-w-r/2){
       mode = 1;
       fill(random(255),random(255),random(255));
      }
      break;
    }
    case 1:{
      y+=s;
      if(y >= height-w-r/2){
        mode = 2;
        fill(random(255),random(255),random(255));
      }
      break;
    }
    case 2:{
      x-=s;
      if(x <= w+r/2){
        mode = 3;
        fill(random(255),random(255),random(255));
        w += 10;
      }
       break;
      }
     
    case 3:{
      y-=s;
      if(y <= w+r/2){
        mode = 0;
        fill(random(255),random(255),random(255));
      }
      break;
    }
    
  }
  if(!(x>180&&x<220&&y>180&&y<220))ellipse(x,y,r,r);
}

