class character{
  PVector pos;
  PVector v;
  float posX,posY,speed,acc;
  int size;
  boolean isjump;  
  
  character(){
    pos = new PVector(width/2,height-size);
    v = new PVector(0,0);
    speed = 0;
    acc = 1;
    size = 40;
    isjump = false;
  }
  
  void update(){    
    
    if(keyState[LEFT]) v.x =- 5;
    else if(keyState[RIGHT]) v.x = 5;
    else v.x = 0;
    
    
    if(keyState[' '] && !p_keyState[' '] && !isjump){
      v.y = -15;
      isjump = true;
    }
    
    if(isjump)v.y += acc;
    if(pos.y < size/2) pos.y = size/2;
    
    pos.add(v);
    
    if(pos.y+size/2 > height){
      pos.y = height-size/2;
      isjump = false;
    }
    if(pos.x > width-size/2) pos.x = width-size/2;
    else if(pos.x < size/2) pos.x = size/2;

  }
  void draw(){
    fill(255,0,0);
    ellipse(pos.x,pos.y,size,size);
  }

};
