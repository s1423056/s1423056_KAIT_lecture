class EfcBall{
  int col;
  int pos_x,pos_y;
  float alp,size;
  boolean end;
  
  EfcBall(int c,int x,int y){
    col = c;
    pos_x = x;
    pos_y = y;
    alp = 150;
    size = 20;
    end = true;
  }
  
  void initialize(){
    alp = 150;
    size = 22;
    end = true;
  }
  
  void update(){
    if(!end){
      size++;
      alp -= 2.5;
      if(alp <= 0){
        alp = 150;
        size = 22;
        end = true;
      }
    }
  }
  
  void drawEfcBall(){
    if(!end){
      switch(col){
        case 0:fill(255,60,30,alp);break;
        case 1:fill(80,225,80,alp);break;
        case 2:fill(128,128,225,alp);break;
        case 3:fill(225,225,30,alp);break;
        case 4:fill(128,60,128,alp);break;
      }
      noStroke();
      ellipse(pos_x,pos_y,size,size);
    }
  }
};

