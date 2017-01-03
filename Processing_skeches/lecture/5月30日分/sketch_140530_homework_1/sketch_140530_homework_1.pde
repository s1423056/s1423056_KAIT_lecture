String str = "Watanabe Syou";
size(600,400);
background(255);
float s = 50;
fill(0);
textAlign(CENTER);
for(int i = 0;i < 5;i++){
  textSize(20+i*15);
  s += textAscent();
  text(str,width/2,s);
}
save("1423056.jpg");
