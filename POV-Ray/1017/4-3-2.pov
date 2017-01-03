#include "colors.inc"
#include "shapes.inc"

camera{
  location <0,10,-10>
  look_at <0,0,0>
  angle 40
}

light_source{<0,10,-10> color White}                 
light_source{<10,-10,-10> color White}
light_source{<0,10,0> color White}        

difference{
  object{ 
    Disk_Y
    scale <3,1,3>
    translate <0,-1,0>
    pigment {color Cyan}
  }
  object{
    Disk_Y
    scale <2.8,1,2.8>
    translate <0,0.2,0>
    pigment {color Yellow}
  }
  object{
    Disk_Z
    scale <0.5,0.5,2>
    translate <0,0,2>
    pigment {color Green}
  }
  object{
    Disk_Z
    scale <0.5,0.5,2>
    translate <0,0,2>
    rotate 120*1*y
    pigment {color Green}
  }
  object{
    Disk_Z
    scale <0.5,0.5,2>
    translate <0,0,2>
    rotate 120*2*y
    pigment {color Green}
  }
}      


background{color LightGray}