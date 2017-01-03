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
  rs[r]+=1;
  int barWidth = int(width/rs.length);
  for(int i=0;i<rs.length;i++){
    if(rs[i]>height){
      rect(barWidth*i,height,width/10,-rs[i]/2);
    }else{
      rect(barWidth*i,height,width/10,-rs[i]);
    }
  }  
}
