int[] scores = { 10000,9000,5000,1000,30 };
PFont font;

void setup(){
  size(300,400);
  smooth();
  font = loadFont("Serif-48.vlw");
  textFont(font,48);
}

void draw(){
  background(255);
  fill(100);
  textAlign(CENTER);
  rectMode(CENTER);
  float topOffset = (height - 60*5)/2
  +textAscent();
  for(int i = 0;i < scores.length;i++){
    text(str(scores[i]),
    width/2,topOffset+60*i,width,60);
  }
}

void mouseClicked(){
  int newScore = int(random(100000));
  println(newScore);
  for(int i = 0;i<5;i++){
    if(newScore >= scores[i]){
      for(int j=5-1;j >i;j--){
        scores[j] = scores[j-1];
      }
      scores[i] = newScore;
      break;
    }
  }
}
