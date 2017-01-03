#include"colors.inc"
#include"shapes.inc"

camera{
  location<0,10,-10>
  look_at<0,0,0>
  angle 20
}

light_source{ <-10,10,-10> color White}
light_source{ <10,10,-10> color White}

object{
  Sphere
  pigment{ color <1,0,1> }
}