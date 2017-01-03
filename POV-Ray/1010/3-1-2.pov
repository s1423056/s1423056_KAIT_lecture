#include "shapes.inc"
#include "colors.inc"

camera{
  location <0,10,150>
  look_at <0,10,0>
  angle 50
}

light_source{<50,50,50> color White}                 
light_source{<0,10,-50> color White}

object{                  //reg
  Disk_Y
  scale <1,4,1>
  translate <0,4,0>
  pigment {color Green}
}
object{                  //body
  Disk_Y
  scale <4,6,4>
  translate <0,14,0>
  pigment {color Blue}
}      
object{                  //arm
  Cube
  scale <14,1,1>
  translate <0,17,0>
  pigment {color Yellow}
}      
object{                  //head
  Sphere
  scale 4
  translate <0,24,0>
  pigment {color Magenta}
}      
object{                  //ambrella
  Cone_Y
  scale <8,2,8>
  translate <0,30,0>
  pigment {color Cyan}
}      
object{                  //grand
  Cube
  scale <20,1,20>
  translate <0,-1,0>
  pigment {color Red}
}                      