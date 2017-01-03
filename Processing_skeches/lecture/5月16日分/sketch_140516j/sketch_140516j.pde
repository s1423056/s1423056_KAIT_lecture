size(350,350);
background(200,0,0);
strokeWeight(50);
stroke(25,0,0,75);

for(int i=0;i<3;i++){
  line(75+100*i,0,75+100*i,height);
}
for(int i=0;i<3;i++){
  line(0,75+100*i,width,75+100*i);
}
