size(400,400);
background(210,200,150);

strokeWeight(200);
stroke(240,230,200,90);

line(width/2,0,width/2,height);
line(0,height/2,width,height/2);

strokeWeight(40);
stroke(95,85,65,90);

for(int i=0;i<3;i++){
  line(80*i+120,0,80*i+120,height);
  line(0,80*i+120,width,80*i+120);
}
