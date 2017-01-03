#include "colors.inc"
#include "shapes.inc"

camera{
  location <0,6,-10>
  look_at <0,0,0>
  angle 30
}

light_source{<-10,0,-10> color White}                 
light_source{<10,10,-10> color White}

object{            
  torus{
    1,
    0.3
  }
  pigment{color Red}
}
object{   
  torus{
    1,
    0.3
  } 
  translate<-1.3,0,0>
  rotate 90*x
  pigment{color Blue}
}
object{  
  torus{
    1,
    0.3
  }
  translate<1.3,0,0>
  rotate 90*x 
  pigment{color Yellow}
} 

background{color White}