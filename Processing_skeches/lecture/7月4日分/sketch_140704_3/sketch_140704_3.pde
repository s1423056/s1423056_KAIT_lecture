float[] y = new float[ 5 ];

void setup() {
  size(400, 200);
  for (int i=0;i< y.length-1 ;i++) {
    y[i] = random(0.3*width, width);
  }
}

void draw() {
  background(255);
  stroke(0);
  y[ 4 ] = mouseX;
  int minPos = findMinPos( y );
  for (int j=0;j<y.length ;j++) {
    fill(128);
    if ( j == minPos) {
      fill( 255 , 10 , 10 );
    }
    rect(0, 40*j+10, y[j], 25);
  }
}

int findMinPos(float[] x) {
  int tentativePos = 0;
  for (int i=1;i<x.length;i++) {
    if ( x[tentativePos] > x[i]) {
      tentativePos = i;
    }
  }
  return tentativePos;
}
