int[] rs;
int[] ps;

void setup(){
  size(400,200);
  rs = new int[10] ;
  for(int i=0;i<rs.length;i++){
    rs[i] = 0 ;
  }
  ps = new int[16] ;
  ps[0] = 0;
  ps[1] = 0;
  ps[2] = 0;
  ps[3] = 0;
  ps[4] = 1;
  ps[5] = 1;
  ps[6] = 1;
  ps[7] = 2;
  ps[8] = 2;
  for(int i=3;i<rs.length;i++){
    ps[6+i] = i ;
  }
}

void draw(){
  background(255);
  stroke(0);
  fill(128);
  int r = ps[int(random(ps.length))];
  rs[r]++;
  int barWidth = int(width/rs.length);
  for(int i=0;i< 10 ;i++){
    rect(barWidth*i,height-rs[i],width/rs.length,height);
  }
}
