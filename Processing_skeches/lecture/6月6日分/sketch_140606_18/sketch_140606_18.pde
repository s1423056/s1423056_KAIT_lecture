boolean right = true;
int x,y,i;
void setup() {
  size(400, 400);
  colorMode(HSB,359,99,99);
  smooth();
  x = width/2;
  y = height/2;
  i = 0;
}

void draw() {
  background(0,0,99);
  fill(50, 95, 95);
  stroke(0,99,0);
  int t = millis();
  i++;
  
  if(pmouseX < mouseX){ //from left to right
    right = true;
    x++;
    arc(x,y,40,40,PI/6-PI/6*sin(i),11*PI/6+PI/6*sin(i),PIE);
  }else if(pmouseX > mouseX){ // from r to l
    right = false;
    x--;
    arc(x,y,40,40,7*PI/6-PI/6*sin(i),17*PI/6+PI/6*sin(i),PIE);
  }else if(right){ //no move right
    arc(x,y,40,40,PI/6,11*PI/6,PIE);
  }else{ // no move left
    arc(x,y,40,40,7*PI/6,17*PI/6,PIE);
  }
  
}
