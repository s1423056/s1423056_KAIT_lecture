float[] x = new float[ 5 ];

void setup(){
  size(400,250);
  for( int i=0;i<x.length-1;i++){
    x[i] = random(0.3*width,width);
  }
}

void draw(){
  background(255);
  stroke(0);
  fill(128);
  x[x.length - 1 ] = mouseX;
  float m = myMin(x);
  for(int i=0;i<x.length ;i++){
    rect(0,40*i+10,x[i],25);
  }
  rect(0,40*x.length+10,m,25);
}

float myMin( float[] x){
  float tentativeMin = x[0];
  for(int i=1;i<x.length ;i++){
    if(tentativeMin > x[i]){
      tentativeMin = x[i] ;
    }
  }
  return tentativeMin;
}
