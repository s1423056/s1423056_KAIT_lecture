#include "shapes.inc"
#include "colors.inc"

camera{
  location <0,12,25>
  look_at <0,0,0>
  angle 50
}

light_source{<0,50,50> color White}     
light_source{<0,10,-50> color White}            


object{                  
  Disk_Y
  scale <1,4,1>
  translate <0,0,6>
  pigment {color Yellow}
  rotate 60*0*y
}
object{                  
  Disk_Y
  scale <1,4,1>
  translate <0,0,6>
  pigment {color Green}
  rotate 60*1*y
}
object{                  
  Disk_Y
  scale <1,4,1>
  translate <0,0,6>
  pigment {color Yellow}
  rotate 60*2*y
}object{                  
  Disk_Y
  scale <1,4,1>
  translate <0,0,6>
  pigment {color Green}
  rotate 60*3*y
}   
object{                  
  Disk_Y
  scale <1,4,1>
  translate <0,0,6>
  pigment {color Yellow}
  rotate 60*4*y
}object{                  
  Disk_Y
  scale <1,4,1>
  translate <0,0,6>
  pigment {color Green}
  rotate 60*5*y
}           
