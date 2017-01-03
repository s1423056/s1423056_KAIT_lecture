class Player extends Objects{
  int counter,i,pace;
  float vX,vY,aY;
  boolean isFRY,sjump;
  PImage img[],jmp;

  Player(){
    img = new PImage[16];
    for(int i = 1;i<16;i++){
      img[i] = loadImage("h_w_r"+i+".png");
    }
    img[0] = loadImage("h_w_1.png");
    jmp = loadImage("h_w_j.png");
  }
  
   void Initialize(){
    i = 0;
    pace = 4;
    isFRY = true;
    sjump = true;
    vX = 2.5;
    vY = 0;
    aY = 0.3;
    posX = width/4;
    posY = height/2;
  }
  
  void Finalize(){}
  
  void Update(){
      counter++;
    
    if(!isFRY){
      vY = 0;
      if(keyState['z'%256]){
        isFRY = true;
        vY = 7.0;
      }
    }else{
      if(sjump && !p_keyState['z'%256] && keyState['z'%256]){
        sjump = false;
        vY = 7.0;
      }
      vY -= aY;
    }
    posY -= vY; 
    
    for(int i = 0;i<floor.length;i++){
      float fx = floor[i].posX;
      float fxl = floor[i].posX - floor[i].f_width/2;
      float fxr = floor[i].posX + floor[i].f_width/2;
      float fh = floor[i].posY - floor[i].f_height/2;
      if(posY+H_imgsize/2 > fh){
        if(posX > fx && posX < fxr+5){
          posX = fxr+5;
        }else if(posX < fx && posX > fxl-5){
          posX = fxl-5;
        }
      }else if(vY <= 0 && posY+H_imgsize/2 < fh +10 && posY+H_imgsize/2 > fh -10){
          if(posX > fxl-10 && posX < fxr+10){
            posY = fh - H_imgsize/2;
            isFRY = false;
            sjump = true;
            break;
          }else{
            isFRY = true;
        }
      }
    }
    
    if(counter >= pace){
      counter = 0;
      if(!isFRY && i < img.length){
        i++;
        if(i == img.length)i = 4;
      }
    }
  }
  
  void Draw(){
    if(isFRY){
      image(jmp,posX,posY);
    }else{
      image(img[i],posX,posY);
    }
  }
  
  void Paceup(){
    if(pace > 1) pace--;
    if(aY < 0.4) aY += 0.02;
  }
}
