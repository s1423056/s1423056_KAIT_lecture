String str1 = "Amano Yumiko";
String str2 = "Kaneda Emiko";
String str3 = "Koji Akako";
String str4 = "Anegasake Nene";
String str5 = "Nishizumi Miho";
String str6 = "Isuzu Hana";

size(600,400);
background(255);
textSize(32);

textAlign(RIGHT);
fill(255,0,0);
text(str1,width/2-10,200);
fill(0,255,0);
text(str3,width/2-10,250);
fill(0,0,255);
text(str5,width/2-10,300);

textAlign(LEFT);
fill(255,255,0);
text(str2,width/2+10,200);
fill(0,255,255);
text(str4,width/2+10,250);
fill(255,0,255);
text(str6,width/2+10,300);
