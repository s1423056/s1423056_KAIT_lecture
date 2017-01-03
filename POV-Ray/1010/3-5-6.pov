#include "shapes.inc"
#include "colors.inc"

camera{
  location <0,5,-10>
  look_at <0,0,0>
  angle 60
}

light_source{<0,10,0> color White}     
light_source{<0,15,-15> color White}            


object{                  
  Disk_Y
  scale <0.5,2,0.5>
  translate <0,0,3>
  pigment {color Yellow}
  rotate 60*0*y
}
object{                  
  Disk_Y
  scale <0.5,2,0.5>
  translate <0,0,3>
  pigment {color Red}
  rotate 60*1*y
}
object{                  
  Disk_Y
 scale <0.5,2,0.5>
  translate <0,0,3>
  pigment {color Green}
   rotate 60*2*y
}object{                  
  Disk_Y
  scale <0.5,2,0.5>
  translate <0,0,3>
  pigment {color Blue}
  rotate 60*3*y
}   
object{                  
  Disk_Y
  scale <0.5,2,0.5>
  translate <0,0,3>
  pigment {color Cyan}
  rotate 60*4*y
}object{                  
  Disk_Y
  scale <0.5,2,0.5>
  translate <0,0,3>
  pigment {color Magenta}
  rotate 60*5*y
}           
