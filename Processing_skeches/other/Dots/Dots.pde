int lMaxNum = 60;
Ball[] b = new Ball[36];
Line[] l = new Line[lMaxNum];
Line actl;
int checkcol;
int checkedBallNum;
boolean wasmousepressed = false;
static boolean[][] appear = {{true,true,true,true,true,true},
                      {true,true,true,true,true,true},
                      {true,true,true,true,true,true},
                      {true,true,true,true,true,true},
                      {true,true,true,true,true,true},
                      {true,true,true,true,true,true},};
int lc_x = -1,lc_y = -1;
static int eSize = 22;

void setup(){
  size(350,350);
  noStroke();
  checkcol = -1;
  checkedBallNum = 0;
  
  for(int i = 0;i<6;i++){
    for(int j = 0;j<6;j++){
      b[i*6+j] = new Ball((int)random(5),i*50+50,j*50+50,i,j);
    }
  }
  for(int i = 0;i<lMaxNum;i++){
    l[i] = new Line();
  }
  actl = new Line();
}

void draw(){
  int i;
  background(255);
  checkedBallNum = 0;
  actl.update();
  actl.drawLine();
  for(i=0;i<lMaxNum;i++) l[i].drawLine();
  for(i = 0;i<36;i++){
    b[i].update();
    b[i].drawellipse();
    if(b[i].check)checkedBallNum++;
  }
  println(checkedBallNum);
  if(mousePressed){
    for(i = 0;i<36;i++){
      if(checkcol == b[i].col && collidecircle(mouseX,mouseY,(int)b[i].pos_x,(int)b[i].pos_y)){
        if((lc_y == b[i].sq_y && lc_x-1 == b[i].sq_x) || 
           (lc_y == b[i].sq_y && lc_x+1 == b[i].sq_x) ||
           (lc_x == b[i].sq_x && lc_y-1 == b[i].sq_y) ||
           (lc_x == b[i].sq_x && lc_y+1 == b[i].sq_y)){
              b[i].check = true;
              lc_x = b[i].sq_x;
              lc_y = b[i].sq_y;
              for(int j = 0;j<lMaxNum;j++){
                if(l[j].enable == false){
                  l[j].initialize(b[i].col,actl.start_x,actl.start_y,(int)b[i].pos_x,(int)b[i].pos_y);
                  break;
                }
              }
              actl.initialize(b[i].col,(int)b[i].pos_x,(int)b[i].pos_y);
              break;
        }
      }
    }
  }
}

void mousePressed(){
  if(!wasmousepressed){
    for(int i = 0;i<36;i++){
      if(collidecircle(mouseX,mouseY,(int)b[i].pos_x,(int)b[i].pos_y)){
        b[i].check = true;
        lc_x = b[i].sq_x;
        lc_y = b[i].sq_y;
        checkcol = b[i].col;
        actl.initialize(b[i].col, (int)b[i].pos_x, (int)b[i].pos_y);
        break;
      }
    }
  }
}

void mouseReleased(){
  lc_x = -1;
  lc_y = -1;
  println(checkedBallNum);
  if(checkedBallNum >= 2){
    for(int i = 0;i<36;i++){
      if(b[i].check){
        b[i].disapp();
        println(b[i].sq_x,b[i].sq_y);
        appear[b[i].sq_x][b[i].sq_y] = false;
      }
    }
  }
  for(int i = 0;i<36;i++){
    b[i].check = false;
    b[i].waschecked = false;
  }
  for(int i = 0;i<lMaxNum;i++){
    l[i].initialize(0,0,0,0,0);
    l[i].enable = false;
  }
  actl.initialize(0,0,0,0,0);
  actl.enable = false;
  wasmousepressed = false;
  checkcol = -1;
  checkedBallNum = 0;
}

boolean collidecircle(int x1, int y1, int x2, int y2){
  int x = (x1-x2)*(x1-x2);
  int y = (y1-y2)*(y1-y2);
  if(x+y < (eSize/2)*(eSize/2))return true;
  return false;
}
