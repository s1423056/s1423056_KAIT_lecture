float[] xBall;
float[] yBall;
float[] vBall;
int numberOfBalls=10;
float radius=10;

void setup(){
  size(400,400);
  smooth();
  xBall = new float [numberOfBalls];
  yBall = new float [numberOfBalls];
  vBall = new float [numberOfBalls];
  for(int i=0;i< numberOfBalls ;i++){
    xBall[i] = width/2;
    yBall[i] = random(radius, height-radius);
    vBall[i] = random(1,2);
    if(random(10) <= 5){
      vBall[i] = -vBall[i];
    }
  }
}

void draw(){
  background(255);
  for(int i=0;i<numberOfBalls;i++){
    xBall[i] += vBall[i];
    if( xBall[i]+radius > width ){
      vBall[i] = -vBall[i];
      xBall[i] = width-radius;
    }else if( xBall[i]-radius<0 ){
      vBall[i] = -vBall[i];
      xBall[i] = radius;
    }
    stroke(255,10,10);
    fill(255,10,10);
    ellipse(xBall[i],yBall[i],
    2*radius,2*radius);
  }
}
