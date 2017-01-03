int startTime;
boolean doing = false; // 時間計測中はtrue にする
PFont font;

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
    float theta = map( ms%1000 ,0,1000,0,2*PI);
    stroke(0);
    fill(50);
    arc(width/2,0.6*height,
    width/2,height/2,
    3*HALF_PI , theta+3*HALF_PI);
    println(radians(theta));
  }
}

String millisToMS(int ms){
  int ts = ms / 1000 ;// ミリ秒を秒に変換
  int s = ts%60 ; // ts から秒の部分を求める
  int m = ts/60 ; // ts から分の部分を求める
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
