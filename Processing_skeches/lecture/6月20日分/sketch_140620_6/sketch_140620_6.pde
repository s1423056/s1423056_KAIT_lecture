int[] rs;
 
void setup(){
  size(400,200);
  rs = new int[10];
  for(int i = 0;i<rs.length;i++){
    rs[i] = 0;
  }
}

void draw(){
  background(255);
  stroke(0);
  fill(128);
  int r = int(random(rs.length));
  rs[r]++;
  int barWidth = int(width/rs.length);
  for(int i=0;i<rs.length;i++){
    rect(barWidth*i,height-rs[i],width/rs.length,height);
    println(r);
  }  
}
