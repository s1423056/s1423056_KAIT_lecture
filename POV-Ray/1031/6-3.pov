#include "colors.inc"
#include "shapes.inc"
#include "woods.inc"


camera{
 location <0,10,10>
 look_at <0,0,0>
 angle 30
}

light_source{ <-10,10,-10> color White}
light_source{ <10,10,-10> color White}
light_source{ <0,10,0> color White}

union{
 object{
   Disk_X
   pigment{color White} 
   scale <1,0.95,0.95>
   translate <-1,0,0>
   finish{
    phong 1.0
    phong_size 7
  }
 }
 object{
   Sphere
   pigment{color White}
   scale 0.95
   translate <-2,0,0>
   finish{
    phong 1.0
    phong_size 7
  }
 }
 object{
   Disk_X
   pigment{color Blue}
   translate <1,0,0>
   finish{
    phong 1.0
    phong_size 7
  }
 }
 object{
   Sphere
   pigment{color Blue}
   translate <2,0,0>
   finish{
    phong 1.0
    phong_size 7
  }
 } 
}



object{
  Plane_XZ
  texture{ T_Wood3 }
  translate <0,-1,0>
}