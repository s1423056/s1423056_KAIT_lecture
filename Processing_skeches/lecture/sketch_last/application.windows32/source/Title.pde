class Title extends Basestate{
  int counter = 0;
  boolean start = false;
  
  void Initialize(){}
  void Finalize(){}
  
  void Update(){
    if(!p_keyState['z'%256] && keyState['z'%256]){
      start = true;
    }
    if(start)counter++;
    if(counter >= 180){
      gamestate = new Main();
    }
  }
  
  void Draw(){
    textAlign(CENTER);
    textSize(40);
    fill(0);
    if(start){
      text((240-counter)/60,width/2,height/2);
    }else{
      text("The Runner",width/2,height/2-40);
      textSize(25);
      text("press Z key to Game Start",width/2,height/2+100);
    }
  }
}
