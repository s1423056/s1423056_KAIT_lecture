PImage ship;
PImage back;
float angle;
float angleVel;
float xPos;
float yPos;
float vx; 
float vy;
float speed;

void initTri(){
  angle = 0;
  angleVel = 0;
  xPos = width/2;
  yPos = height/2;
  vx = vy = 0;
  speed = 0;
}

void setup(){
  size(300,300);
  initTri();
  ship = loadImage("cannon-a.png");
  back = loadImage("nebula-blue.png");
}

void drawShip(){
  pushMatrix();
  translate(xPos,yPos);
  rotate(radians(angle));
  imageMode(CENTER);
  image(ship,0,0);
  popMatrix();
}

void draw(){
  image(back,0,0);
  drawShip();
  angle += angleVel;
  xPos += vx ;
  yPos += vy ;
}

void keyPressed(){
  if(key == 'r' || key == 'R' ){
     initTri();
  }else if(key == CODED){
    if(keyCode == LEFT){
      angleVel = -1;
    }else if(keyCode == RIGHT){
      angleVel = 1;
    }else if(keyCode == UP){
      float theta = radians(angle-90);
      println(radians(angle)+PI/4);
      speed = 2;
      vx = speed * cos(theta);
      vy = speed * sin(theta);
    }
  }
}

void keyReleased(){
  if(key == CODED){
    if(keyCode == LEFT || keyCode == RIGHT){
      angleVel = 0;
    }else if(keyCode == UP){
      vx = 0;
      vy = 0 ;
      speed = 0;
    }
  }
}
