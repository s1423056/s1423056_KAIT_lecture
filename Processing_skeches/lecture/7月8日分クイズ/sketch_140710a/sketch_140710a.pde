String[] moji;
PFont font;

void setup(){
  size(800,300);
  font = loadFont("HGMinchoB-48.vlw");
  textFont(font,36);
  moji = loadStrings("q12.txt");
}

void draw(){
  background(255);
  fill(0);
  textAlign(CENTER);
  for(int i = 0;i<moji.length;i++){
    text(moji[i],0,i*50+60,width,height);
  }
}
