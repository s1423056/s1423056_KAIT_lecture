import  ddf.minim.*;  
import  ddf.minim.signals.*;  
import  ddf.minim.analysis.*;  
import  ddf.minim.effects.*;  
Minim  minim;  
AudioPlayer  player;  
float  xBall,yBall,rBall;;  
void  setup(){  
    minim  =  new  Minim(this);  
    player  =  minim.loadFile( "schoolsong.mp3" );  
    size(400,400);  
    smooth();  
    xBall  =  width/2;  
    yBall  =  height/2;  
    rBall  =  width/4;  
}  
void  draw(){  
    background(255);  
    if(player.isPlaying() == true){  
        xBall  =     constrain(xBall+random(-5,5),50,width-50);  
        yBall  =     constrain(yBall+random(-5,5),50,height-50);  
        rBall  =     constrain(rBall+random(-1,1),3,0.5*width);  
    }  
    stroke(255,10,10);  
    fill(255,10,10);  
    ellipse(xBall,yBall,2*rBall,2*rBall);  
}  
void  mouseClicked(){  
    player.rewind();  
    player.play();  
}  
  
void  stop(){  
    player.close();  
    minim.stop();  
    super.stop();  
}  
