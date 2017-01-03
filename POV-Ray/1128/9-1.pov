#include "colors.inc"
#include "shapes.inc"

camera{
 location <1,0,-8>
 look_at <0,0,0>
 angle 30
}

light_source{ <-10,10,-10> color White}
light_source{ <10,10,-10> color White}
   
object{
  Disk_Y
  pigment{image_map{jpeg "9-1.jpg" map_type 1}}
}   