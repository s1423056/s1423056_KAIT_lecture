int[] scores = {10000,9000,5000,1000,30,-1};
PFont font;

void setup(){
  size(300,400);
  smooth();
  font = loadFont("Serif-48.vlw");
  textFont(font,48);
}

void mouseClicked(){
  int newScore = int(random(100000));
  println(newScore);
  scores[5] = newScore;
  int idx = 0;
  while(scores[idx] > newScore){
    idx++;
  }
  for(int i=5-1;i>idx;i--){
    scores[i] = scores[i-1];
  }
  scores[idx] = newScore ;
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
