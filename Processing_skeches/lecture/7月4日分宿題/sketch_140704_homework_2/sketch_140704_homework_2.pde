int[] x;
String name = "Watanabe Syou" ;
PFont font;

void setup(){
  size(400,300);
  smooth();
  x = new int[5];
  for(int i=0;i<x.length ;i++){
    x[i] = int(random(width));
  }
  font = loadFont( "Serif.plain-48.vlw" );
  textFont(font,36);
}

void draw(){
  background(255);
  fill(0);
  for(int i=0;i<x.length;i++){
    x[i]--;
    if( x[i]+textWidth(name) < 0){
      x[i] = width;
    }
    text(name, x[i] ,60*i+40);
  }
}
