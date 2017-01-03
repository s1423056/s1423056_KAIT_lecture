#include "colors.inc"
#include "shapes.inc" 

#declare r = 3;

camera{
 location <0,15,-20>
 look_at <0,0,0>
 angle 30
}

light_source{
 <-1,3.5,-1>
 color White
 spotlight
 point_at <r, 1, -3>
 radius 10 
 falloff 30
}


object{
  Sphere
  pigment{color Red}
  translate <r,1,-3>
}


object{
  Plane_XZ
  pigment{checker color White, color Black}
}