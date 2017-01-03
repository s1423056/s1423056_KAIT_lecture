#include "colors.inc"
#include "shapes.inc"

camera{
  location <0,0,-10>
  look_at <0,0,0>
  angle 40
}

light_source{<0,10,-10> color White}                 
light_source{<10,-10,-10> color White}
        

union{
  object{ 
    Disk_Y
    translate <0,-1,0>
    pigment {color Cyan}
  }
  object{
    Sphere
    translate <0,0,0>
    pigment {color Green}
  }
}