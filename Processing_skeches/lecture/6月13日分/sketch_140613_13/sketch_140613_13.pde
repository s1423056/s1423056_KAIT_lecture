int startTime;
boolean doing = false;
PFont font;
boolean bflag = true;

void setup(){
  size(400,400);
  smooth();
  font = createFont("HGMinchoB-48.vlw",48) ;
  textFont(font,48);
  textAlign(CENTER);
}

void draw(){
  background(255);
  if(doing){
    int ms = millis() - startTime ;
    fill(0);
    text(millisToMS( ms ),width/2,height/5);
    float theta = map( ms%1000,0,1000,0,2*PI );
    stroke(0);
    if(bflag){
      fill(255);
      ellipse( width/2 , 0.6*height , width/2 , height/2 );
      fill(50);
      arc( width/2 , 0.6*height , width/2 , height/2 , 3*HALF_PI , 3*HALF_PI + theta );
    }
    if(!bflag){
      fill(50);
      ellipse( width/2 , 0.6*height , width/2 , height/2 );
      fill(255);
      arc( width/2 , 0.6*height , width/2 , height/2 , 3*HALF_PI , 3*HALF_PI + theta );
    }
  }
}

String millisToMS(int ms){
  int ts = ms / 1000;
  int s = ts%60;
  if(s % 2 == 0){
    bflag = true;
  }else{
    bflag = false;
  }
  int m = ts/60;
  return str(m) + "m" + str(s) + "s";
}

void mouseClicked(){
  if(doing == false){
    doing = true ;
    startTime = millis();
  }else{
    doing = false ;
  }
}
