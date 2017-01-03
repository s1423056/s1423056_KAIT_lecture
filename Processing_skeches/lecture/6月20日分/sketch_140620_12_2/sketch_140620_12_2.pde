float[] xBall;
float[] yBall;
float[] vBall;
int numberOfBalls=10;
float radius=10;

void setup(){
  size(400,400);
  smooth();
  xBall = new float[numberOfBalls];
  yBall = new float[numberOfBalls];
  vBall = new float[numberOfBalls];
  for(int i=0;i<numberOfBalls;i++){
    xBall[i] = width/2;
    yBall[i] = random(radius,
    height-radius);
    vBall[i] = random(1,2);
    if(random(10) <= 5){
      vBall[i] = -vBall[i];
    }
  }
}

void draw(){
  background(255);
  for(int i=0;i<numberOfBalls;i++){
    moveBall(i);
    drawBall(i);
  }
}

void drawBall(int idx){
  stroke(255,10,10);
  fill(255,10,10);
  ellipse(xBall[ idx ],yBall[ idx ],
  2*radius,2*radius);
}

void moveBall(int idx){
  xBall[idx] += vBall[idx];
  if( xBall[idx]+radius > width){
    vBall[idx] = -vBall[idx];
    xBall[idx] = width-radius;
  }else if(xBall[idx]-radius < 0){
    vBall[idx] = -vBall[idx];
    xBall[idx] = radius;
  }
}
