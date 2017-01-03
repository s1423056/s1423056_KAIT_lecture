int[] scores;
PFont font;

void setup(){
  size(300,400);
  smooth();
  scores = new int[5];
  scores[0] = 10000;
  scores[1] = 9000;
  scores[2] = 5000;
  scores[3] = 1000;
  scores[4] = 30;
  font = loadFont("Serif-48.vlw");
  textFont(font,48);
}

void draw(){
  background(255);
  fill(100);
  textAlign(CENTER);
  rectMode(CENTER);
  float topOffset = (height - 60 * 5)/2+textAscent();
  for(int i = 0;i < 5;i++){
    text(scores[i],width/2,topOffset+60*i,width) ;
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
