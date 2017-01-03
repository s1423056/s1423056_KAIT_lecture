#include "colors.inc"
#include "shapes.inc"
#include "skies.inc"

camera{
 location <4,4,-8>
 look_at <0,0,0>
 angle 25
}

light_source{ <-10,10,-10> color White}
light_source{ <10,10,-10> color White}

superellipsoid{
 <1.0,0.5>
 pigment{checker White*1.2, color  rgb<0.9,0.6,0.2> scale 2.5}
 finish{phong 1}
 scale 1.0
 translate <0,0,0>
 rotate x*90
}
