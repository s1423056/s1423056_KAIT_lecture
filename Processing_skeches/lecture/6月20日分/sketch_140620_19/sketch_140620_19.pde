int[] x1,x2;
int[] y1,y2;
color[] c;
color t;
boolean ok = false;

void setup(){
  size(600,600);
  x1 = new int[5];
  x2 = new int[5];
  y1 = new int[5];
  y2 = new int[5];
  c = new color[5];
  Initialize();
}

void Initialize(){
  for(int i=0;i<5;i++){
    x1[i] = int(random(150,width-150));
    x2[i] = int(random(75,150));
    y1[i] = int(random(150,height-150));
    y2[i] = int(random(75,150));
    c[i] = color(int(random(0,255)),int(random(0,255)),int(random(0,255)));
    t = color(c[0]);
  }
}

void draw(){
  background(255);
  for(int i = 0;i<5;i++){
    fill(c[i]);
    rect(x1[i],y1[i],x2[i],y2[i]);
  }
   if(mouseX>=x1[0]&&mouseX<=x1[0]+x2[0]&&mouseY>=y1[0]&&mouseY<=y1[0]+y2[0]){
    c[0] = color(255,0,0);
  }else{
    c[0] = t;
  }
  println(x1[0],x1[0]+x2[0],y1[0],y1[0]+y2[0]);
  println(mouseX,mouseY);

}

void mouseClicked(){
  if(mouseX>=x1[0]&&mouseX<=x1[0]+x2[0]&&mouseY>=y1[0]&&mouseY<=y1[0]+y2[0]){
    Initialize();
  }else{
    
  }
}
