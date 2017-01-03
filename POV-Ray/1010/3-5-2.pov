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
  translate<0,0,3>
  rotate 60*y
  pigment {color Red}
} 
object{                  
  Disk_Y
  scale <0.5,2,0.5>
  translate<0,0,0>
  rotate 60*y
  pigment {color White}
}