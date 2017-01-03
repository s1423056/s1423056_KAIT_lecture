float[]  x  =  new  float[4];  
  
void  setup(){  
    size(400,200);  
    x[0]  =  random(0.3*width,width);  
    x[1]  =  random(0.3*width,width);  
    x[2]  =  random(0.3*width,width);  
}  
  
void  draw(){  
    background(255);  
    stroke(0);  
    fill(128);  
    x[3]  =  mouseX;  
    float  m4  =  myMin(x);  
    for(int  i=0;i<x.length;i++){  
        rect(0,40*i+10,x[i],25);  
    }  
    rect(0,170,m4,25);  
}  
  
float myMin(float[] x){  
    float  tentativeMin  =  x[0];  
    for(int i=1;i<x.length;i++){  
        if(tentativeMin > x[i]){  
            tentativeMin = x[i]   ;  
        }  
    }  
    return       tentativeMin  ;  
}
