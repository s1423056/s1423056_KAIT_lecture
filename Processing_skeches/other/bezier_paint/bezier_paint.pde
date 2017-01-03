int[] x1 = new int[256];
int[] x2 = new int[256];
int[] x3 = new int[256];
int[] x4 = new int[256];
int[] y1 = new int[256];
int[] y2 = new int[256];
int[] y3 = new int[256];
int[] y4 = new int[256];

int num = 0;
int num2 = 0;

void setup(){  
  size(300,300);
  noFill();
  for(int i=0;i<256;i++){
    x1[i] = 0;
    x2[i] = 0;
    x3[i] = 0;
    x4[i] = 0;
    y1[i] = 0;
    y2[i] = 0;
    y3[i] = 0;
    y4[i] = 0;
  }
}

void draw(){
  background(255);
  if(num2 % 4 == 2 || num2 % 4 == 3){
    x2[num] = mouseX;
    x3[num] = mouseX;
    y2[num] = mouseY;
    y3[num] = mouseY;
  }
  stroke(255,102,0);
  for(int i = 0;i < 256;i++){
    bezier(x1[i],y1[i],x2[i],y2[i],x3[i],y3[i],x4[i],y4[i]);
  }
  stroke(0);
  line(0,mouseY,width,mouseY);
  line(mouseX,0,mouseX,height);
}

void mouseClicked(){
  if(num2 % 4 == 0){
    x1[num] = mouseX;
    y1[num] = mouseY;
    println("x1:",x1[num]," y1:",y1[num]);
  }else if(num2 % 4 == 1){
    x4[num] = mouseX;
    y4[num] = mouseY;
    println("x4:",x4[num]," y4:",y4[num]);
  }else if(num2 % 4 == 2){
    x2[num] = mouseX;
    y2[num] = mouseY;
    println("x2:",x2[num]," y2:",x2[num]);
  }else if(num2 % 4 == 3){
    x3[num] = mouseX;
    y3[num] = mouseY;
    println("x3:",x3[num]," y3:",x3[num]);
    num++;
  }
  num2++;
}
