void setup(){
size(600,200);
}
void draw(){
background(50);
fill(240);
stroke(240);
float xMax = map(seconds(), 0 , 24*3600 , 0 , width );
rect(0,0,xMax,height);
}

int seconds(){
int h = hour();
int m = minute();
int s = second();
return h*3600 + m*60 +s ;
}
