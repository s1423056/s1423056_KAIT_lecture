boolean alive= false ;//赤い円を表示するかを決める変数
float xPos = 0; // 赤い円の中心座標
float yPos = 0;
float vx = 0; // 赤い円の移動ベクトル
float vy = 0;
float speed = 0; // 赤い円の速さ

void setup(){
  size(400,400);
  smooth();
}

void draw(){
  background(255);
  stroke(0);
  line(0,0,mouseX,mouseY);
  noStroke();
  fill(255,0,0);
  if(alive){
    ellipse( xPos , yPos ,20,20);
    xPos += vx ;
    yPos += vy ;
  // ウインドウの外に出たら赤い円の表示をやめる
    if((xPos-20/2 >= width) || (yPos-20/2 >= height)){
      alive = false ;
    }
  }
}

void mouseClicked(){
  float theta = atan2(mouseY,mouseX);
  xPos = 0;
  yPos = 0;
  speed = 2;
  vx = speed * cos( theta );
  vy = speed * sin( theta );
  alive = true ;
}
