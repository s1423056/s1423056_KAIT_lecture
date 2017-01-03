#include "colors.inc"
#include "shapes.inc"   

camera{
 location <0,10,-10>
 look_at <0,0,0>
 angle 30
}

light_source{
 <3,6,4>
 color Yellow
 area_light
 <2, 0, 0>
 <0, 2, 0>,
 10,10
}

object{
  Sphere
  scale 2
  pigment{ color Green }
  translate <0,1,0>
}

object{
  Plane_XZ
  pigment{ checker color White,color Black }
}