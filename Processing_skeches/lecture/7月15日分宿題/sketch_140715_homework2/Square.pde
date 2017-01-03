class Square{
  float xCenter;
  float yCenter;
  float length;
  float rot;
  float spinSpeed;
  color col;
  
  Square(float ss){
    length = random(10,20);
    xCenter = random(length/2 , width-length/2);
    yCenter = random(length/2 , height-length/2);
    col = color(random(360),random(50,100),random(50,100));
    spinSpeed = ss;
    rot = 0;
  }
  
  void update(){
    yCenter += 1;
    rot += spinSpeed;
    if(yCenter - length/2 > height){
      yCenter = -length/2;
    }
  }
  
  void draw(){
    rectMode(CENTER);
    stroke(col);
    fill(col);
    pushMatrix();
    translate(xCenter,yCenter);
    rotate(rot);
    rect(0,0,length,length);
    popMatrix();
  }
  
}
