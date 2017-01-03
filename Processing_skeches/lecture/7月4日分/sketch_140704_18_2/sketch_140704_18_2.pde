int boardSize = 10;
int[][] board = new int[boardSize][boardSize];

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

void setupBoard(int[][] b){
  for(int i=0;i< 10 ;i++){
    for(int j=0;j< 10 ;j++){
      b[i][j] = int(random(0,3)) ;
    }
  }
}

void setup(){
  size(400,400);
  smooth();
  setupBoard(board);
}

void draw(){
  background(255);
  stroke(0);
  strokeWeight(3);
  for(int i=0;i<board.length;i++){
    int y=40*i;
    for(int j=0;j<board[i].length;j++){
      int x=40*j;
      if(board[i][j]==0){
        crossPipe (x,y,40);
      }else if(board[i][j] == 1){
        bendedPipe0 (x,y,40);
      }else{
        bendedPipe1 (x,y,40);
      }
    }
  }
}

void mouseClicked(){
  int x=mouseX/40;
  int y=mouseY/40;
  board[ y ][ x ] = (board[ y ][ x ] + 1 ) % 3 ;
}

