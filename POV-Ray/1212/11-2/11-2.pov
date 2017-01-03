#include "colors.inc"
#include "shapes.inc"

camera{
  location < 0,10,-20>
  look_at <0,0,0>
  angle 25
}

light_source{<2,5,-3> color White}
light_source{<-5,15,-30> color White}
    
object {
  Plane_XZ
  pigment{checker color White color Black}
  translate<0,-1,0>
}

object {
  Sphere
  pigment {color rgb<clock,0.1,(1-clock)>}
  translate <clock*8-4,1,0>
}