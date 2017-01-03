float angle; 
float angleVel;

void setup(){
  size(300,300);
  angle = 0;
  angleVel = 0;
}

void draw(){
  background(255);
  translate(width/2,height/2);
  rotate (radians(angle));
  fill(0,0,255);
  triangle(0,-20,-10,5,10,5);
  angle += angleVel ;
}

void keyPressed(){
  if(key == CODED){
    if(keyCode == LEFT ){
      angleVel = -1;
    }else if(keyCode == RIGHT ){
      angleVel = 1;
    }
  }
}

void keyReleased(){
  if(key == CODED ){
    if(keyCode == LEFT || keyCode == RIGHT ){
      angleVel = 0;
    }
  }
}
