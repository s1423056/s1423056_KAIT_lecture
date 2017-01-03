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
  Sphere
  pigment {color Blue}
  translate <0,0,0>
}