class Line{
  int col;
  int start_x,start_y,end_x,end_y;
  boolean enable;
  
  void Line(){
    col = 0;
    start_x = 0;
    start_y = 0;
    end_x = 0;
    end_y = 0;
    enable = false;
  }
  
  void initialize(int c, int sx, int sy){
    col = c;
    start_x = sx;
    start_y = sy;
    end_x = mouseX;
    end_y = mouseY;
    enable = true;
  }
  
  void initialize(int c, int sx, int sy, int ex, int ey){
    col = c;
    start_x = sx;
    start_y = sy;
    end_x = ex;
    end_y = ey;
    enable = true;
  }
  
  void initialize(int c, int sx, int sy, int ex, int ey, boolean e){
    col = c;
    start_x = sx;
    start_y = sy;
    end_x = ex;
    end_y = ey;
    enable = e;
  }
  
  void update(){
    end_x = mouseX;
    end_y = mouseY;
  }
  
  void drawLine(){
    if(enable){
      strokeWeight(3);
      switch(col){
          case 0:stroke(255,60,30,150);break;
          case 1:stroke(80,225,80,150);break;
          case 2:stroke(128,128,225,150);break;
          case 3:stroke(225,225,30,150);break;
          case 4:stroke(128,60,128,150);break;
        }
      line(start_x,start_y,end_x,end_y);
    }
  }
};
