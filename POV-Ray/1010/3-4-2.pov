#include "shapes.inc"
#include "colors.inc"

camera{
  location <0,5,-5>
  look_at <0,0,0>
  angle 60
}

light_source{<0,10,0> color White}                 
light_source{<0,15,-15> color White}

object{                  
  Disk_Y
  scale <0.5,2,0.5>
  pigment {color Red}
}