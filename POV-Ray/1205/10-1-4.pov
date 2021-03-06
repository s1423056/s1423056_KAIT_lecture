#include "colors.inc"
#include "shapes.inc" 
#include "textures.inc"

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
  Cone_Y
  pigment{Yellow}
  translate<0,1,0>
}
object {
  Sphere
  pigment {Red}
  translate <-4,1,0>
  rotate<0,1-clock*360,0>
}