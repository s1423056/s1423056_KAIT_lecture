PFont font;
String[] col1;
String[] col2;
int idx;

void setup(){
  size(400,200);
  font = loadFont("Meiryo-48.vlw");
  textFont(font, 36);
  String[] lines = loadStrings("test.csv");
  col1 = new String[7];
  col2 = new String[7];
  for(int i = 0;i<7;i++){
    String[] items = split(lines[i],",");
    col1[i] = items[0];
    col2[i] = items[1];  
  }
  idx = 0;
}

void draw(){
  background(255);
  fill(0);
  text(col1[idx],30,50,width-30,50);
  text(col2[idx],30,100,width-30,50);
}

void mouseClicked(){
  idx = (idx + 1) % 7;
}
