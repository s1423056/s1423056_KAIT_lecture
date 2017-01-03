int[][] gray = {{255, 100 , 0 , 51},
{ 100 , 80 , 128,0 },
{ 0, 60 , 30 , 255 },
{ 255 , 127 , 63 ,31}};

void setup(){
  size(400,400);
}

void draw(){
  stroke(0);
  for(int i=0;i< 4 ;i++){
    for(int j=0;j< 4 ;j++){
      fill(gray[ i ][ j ]);
      rect(100* j ,100* i,100,100);
    }
  }
}
