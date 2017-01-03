#include "shapes.inc"
#include "colors.inc"
#include "textures.inc"
#include "skies.inc"

camera{
  location <40,20,-40>
  look_at <0,20,0>
  angle 40
}

light_source{y*2 color White parallel}
light_source{x*2 color White parallel}

sky_sphere{S_Cloud1}

object{
  Plane_XZ
  pigment{color Feldspar}
}

object{
  prism{
    linear_sweep
    -20,
    20,
    3
    <cos(0),sin(0)>,
    <cos(pi),sin(pi)>,
    <cos(pi/2),sin(pi/2)>*2
    scale <14,0.9,8>
    rotate z*90
    rotate x*-90
    translate <0,28,5>
    texture{DMFWood5}
  }
}

