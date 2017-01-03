class Ball{
    int col;
    float pos_x,pos_y;
    int sq_x,sq_y,end_y;
    boolean check,waschecked;
    EfcBall efcball;
    
    Ball(int c, int px, int py, int sx, int sy){
      col = c;
      pos_x = px;
      pos_y = py;
      sq_x = sx;
      sq_y = sy;
      check = false;
      waschecked = false;
      efcball = new EfcBall(col,(int)pos_x,(int)pos_y);
    }
    
    void update(){
      if(check && !waschecked){
        efcball.end = false;
        waschecked = true;
      }
      efcball.update();
      efcball.drawEfcBall(); 
    }
    
    void drawellipse(){
      switch(col){
        case 0:fill(255,60,30);break;
        case 1:fill(80,225,80);break;
        case 2:fill(128,128,225);break;
        case 3:fill(225,225,30);break;
        case 4:fill(128,60,128);break;
      }
      noStroke();
      ellipse(pos_x, pos_y, eSize, eSize);
    }
    
    void disapp(){
       pos_y = -eSize;
       col = (int)random(5);
       check = false;
       waschecked = false;
    }
};

