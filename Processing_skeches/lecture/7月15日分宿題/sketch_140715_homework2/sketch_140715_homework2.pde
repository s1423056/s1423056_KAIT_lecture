int numberOfSquares = 100;
Square[] mySquares;

void setup(){
  size(400,400);
  smooth();
  colorMode(HSB,359,99,99);
  mySquares = new Square[numberOfSquares];
  for(int i = 0;i<numberOfSquares;i++){
    mySquares[i] = new Square(random(PI/64,PI/16));
  }
}

void draw(){
  background(0,0,99);
  for(int i = 0;i<numberOfSquares;i++){
    mySquares[i].update();
    mySquares[i].draw();
  }
}
