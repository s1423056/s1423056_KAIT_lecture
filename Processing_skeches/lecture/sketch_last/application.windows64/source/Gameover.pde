class Gameover extends Basestate {
  boolean newrecord;
  int score;
  int hiscore;
  
  Gameover(int s,int h){
    score = s;
    hiscore = h;
    if(score >= hiscore){
      newrecord = true;
    }else{
      newrecord = false;
    }
    if(newrecord){
      Writefile();
    }
    bgm2.play();
  }
  
  void Initialize(){
    bgm2.play();
  }
  
  void Finalize(){
    bgm2.pause();
    bgm2.rewind();
  }
  
  void Writefile(){
    PrintWriter output;
    output = createWriter("data/score.txt");
    
    output.println(hiscore);
    output.flush();
    output.close();
    println("Newrecord was saved.");
  }
  
  void Update(){
    if(!p_keyState['z'%256] && keyState['z'%256]){
      Finalize();
      gamestate = new Title();
    }
  }
  
  void Draw(){
    textAlign(CENTER);
    fill(0);
    textSize(40);
    text("GAME OVER",width/2,height/2-50);
    textSize(30);
    text("your score : "+score+"m",width/2,height/2+50);
    textSize(20);
    text("press Z key to return to Title",width/2,height/2+180);
    
    if(newrecord){
      fill(255,0,0);
      textSize(40);
      text("New Record!",width/2,height/2+120);
    }
  }
}
