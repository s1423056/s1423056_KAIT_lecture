class Floor extends Objects{
  boolean flag;
  boolean nextfloor;
  float vX;
  float f_width;
  float f_height;
  
  void Initialize(){
    flag = true;
    nextfloor = true;
    vX = 3.0;
    f_width = 1000;
    f_height = 100;
    posX = width/2;
    posY = height;
  }
  
  void Initialize(int num,float v){
    flag = true;
    nextfloor = true;
    vX = v;
    
    posY = height;
    switch(num){
      case 0:
        f_width = 400;
        f_height = 100;
        break;
      case 1:
        f_width = 300;
        f_height = 50;
        break;
      case 2:
        f_width = 200;
        f_height = 100;
        break;
      case 3:
        f_width = 400;
        f_height =50;
        break;
      case 4:
        f_width = 300;
        f_height = 100;
        break;
      default:
        f_width = 600;
        f_height = 100;
        break;
    }
    posX = width + 2*f_width/3+random(-50,50);
  }
  
  void Finalize(){
    flag = false;
    nextfloor = false;
    posX = 0;
    posY = 0;
    f_width = 0;
    f_height = 0;
  }
  
  void Update(){
    posX -= vX;
  }
  
  void Draw(){
    if(flag){
      strokeWeight(2);
      fill(0,0,255,50);
      rectMode(CENTER);
      rect(posX,posY,f_width,f_height);
    }
  }
}
