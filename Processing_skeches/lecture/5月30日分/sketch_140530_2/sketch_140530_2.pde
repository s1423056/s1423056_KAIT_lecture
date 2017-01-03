PFont font;
font = loadFont("HGSGothicE-48.vlw");

size(400,400);
background(255);
colorMode(HSB,360,100,100);
textFont(font,20);

String[] str = new String[4];
str[0] = "Yamagisi Morio 1423055";
str[1] = "Nogawa Ryuunosuke 1423057";
str[2] = "Sgawara Ayaka 1423058";
str[3] = "Yagi Takuya 1423059";

for(int i = 0; i<4;i++){
  fill(i*60,99,99);
  text(str[i],40,80*i+80);
}
save("自分の学籍番号.jpg");
