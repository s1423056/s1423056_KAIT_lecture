float angle; // 回転角度を表す変数
float angleVel; // 回転角度の増分を指定する変数
float xPos; // 三角形の位置座標
float yPos;
float vx; // 三角形の移動ベクトル
float vy;
float speed; // 三角形の速さ

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
}

void drawShip(){
  pushMatrix();
  translate(xPos,yPos);
  rotate(radians(angle)) ;
  fill(0,0,255);
  triangle(0,-20,-10,5,10,5);
  popMatrix();
}

void draw(){
  background(255);
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
