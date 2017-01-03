float[] x;
float[] y;
float[] v;
int radius;
void setup(){
  size(300,400);
  smooth();
  radius = 10;
  x = new float[3];
  y = new float[3];
  v = new float[3];
  for(int i = 0; i < 3; i++){
    v[i] = random(1,2);
    y[i] = -random(radius,2*radius);
    x[i] = random(radius,width-radius);
 }
}

void draw(){
  background(255);
  
  for(int i = 0; i < 3;i++){
    y[i] = y[i]+v[i];
    if(y[i] -radius > height){
      x[i] = random(radius,width-radius);
      y[i] = -random(radius,2*radius);
    }
    stroke(255,10,10);
    fill(255,10,10);
    ellipse(x[i],y[i],2*radius,2*radius);
  }
}
