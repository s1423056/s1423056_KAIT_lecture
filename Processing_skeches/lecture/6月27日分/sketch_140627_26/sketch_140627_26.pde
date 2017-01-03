String msg = "STRINGS";
PFont font;
void setup(){
size(500,200);
font = loadFont("MS-PMincho-48.vlw");
textFont(font,48);
textAlign(CENTER);
fill(0);
}
void draw(){
background(255);
fill(0);
float dx = width/msg.length();
int pos = round(mouseX/dx);
text( msg.substring( 0, int(map(mouseX,0,width,0,msg.length()+1)) ),
width/2,height/2);
}
