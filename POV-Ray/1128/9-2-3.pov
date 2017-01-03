#include "colors.inc"
#include "shapes.inc"

camera{
 location <0,5,-5>
 look_at <0,0,0>
 angle 30
}

light_source{ <8,0,-15> color White}
light_source{ <-8,0,-15> color White}
   
height_field{
  jpeg "9-2.jpeg"
  smooth
  water_level 0.1
  rotate x*270
  pigment{color White}
  
  translate<-0.5,-0.5,0>
  scale<2,2,0.5>
}