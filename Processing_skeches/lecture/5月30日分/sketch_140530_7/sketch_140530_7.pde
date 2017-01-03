 PImage img1,img2;
void setup(){
  size(400,400);
  background(255);
  img1 = loadImage("face1.png");
  img2 = loadImage("face2.png");
}
void draw(){
  if(mousePressed){
    image(img1,0,0);
  }else{image(img2,0,0);
  }
}

