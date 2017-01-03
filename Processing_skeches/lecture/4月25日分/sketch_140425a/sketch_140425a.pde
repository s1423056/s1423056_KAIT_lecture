size(400,400);
background(255);
noStroke();

int x1,y1;
x1 = 100;
y1 = 40;

fill(0,100,50);
rect(40,20,320,360);

fill(255);
//rect(100,40,200,300);

rect(x1,y1,200,300);
quad(x1 , y1+300 , x1+200 , y1+300 , x1+240, y1+340, x1+40, y1+340);

//head
fill(0,100,50);
ellipse(x1+55,y1+30,40,40);

//body
stroke(0,100,50);
strokeWeight(50);
strokeCap(ROUND);
line(x1+70,y1+75,x1+100,y1+150);

//arm
strokeWeight(30);
line(x1+70,y1+65,x1+130,y1+65);
line(x1+130,y1+65,x1+155,y1+105);

line(x1+65,y1+65,x1+30,y1+105);
line(x1+30,y1+105,x1,y1+105);

//reg
stroke(255);
ellipse(x1+200,y1+230,10,10);
stroke(0,100,50);
line(x1+110,y1+150,x1+120,y1+230);
line(x1+120,y1+230,x1+200,y1+230);

line(x1+90,y1+150,x1+40,y1+280);

//shade of reg
line(x1+55,y1+315,x1+105,y1+360);

//hide shade of reg
noStroke();
fill(255);
rect(40,380,320,20);
