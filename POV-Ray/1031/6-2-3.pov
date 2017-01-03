#include"colors.inc"
#include"shapes.inc"
#include"glass.inc"

camera{
  location<0,8,0>
  look_at<0,0,0>
  angle 30
}

light_source{ <-10,10,-10> color White }
light_source{ <10,10,-10> color White }

object{
  Sphere
  pigment{color Clear}
  finish{ F_Glass1 }
  interior{
    I_Glass1
    fade_color Col_Emerald_03
    ior 1.33
  }
}

object{
  Plane_XZ
  pigment{radial}
  translate <0,-3,0>
}

