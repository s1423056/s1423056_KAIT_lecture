PImage[] bgImages;
int[][] bgID;

void setupBackground(){
  bgImages = new PImage[10];
  for(int i=0;i < 10;i++){
    bgImages[i] = loadImage("space"+i+".png");
  }
  bgID = new int[ 10 ][ 15 ];
  for(int i=0;i< 10 ;i++){
    for(int j=0;j< 15 ;j++){
      bgID[i][j] = int(random( 0,10 ));
    }
  }
}

void setup(){
  size(320,480);
  setupBackground();
}

void draw(){
  background(255);
  for(int x=0;x< 10 ;x++){
    for(int y=0;y< 15 ;y++){
      image(bgImages[bgID[ x ][ y ]], bgImages[bgID[x][y]].width*x, bgImages[bgID[x][y]].height*y);
    }
  }
}
