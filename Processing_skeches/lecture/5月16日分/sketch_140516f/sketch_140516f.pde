boolean indent = false;
size(400,400);
smooth();
noStroke();
background(255,127,0);
fill(0,127,255);
for(int y = 0; y < 20;y++){
  for(int x = 0; x < 21;x++){
    if(indent == true){
      ellipse( 20*x,10+20*y ,15 , 15);
    }else{
      ellipse( 10+20*x,10+20*y ,15 ,15 );
    }
  }
indent = !indent;
}
