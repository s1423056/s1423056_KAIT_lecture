#include "colors.inc"
#include "shapes.inc"

camera{
  location <0,2,-4>
  look_at <0,0,0>
}

light_source{<0,10,-10> color White}                 
light_source{<0,10,0> color White}

union{
  difference{
    object{
      Disk_Y
      scale <1,0.91,1>
      pigment {color Cyan}
    }
    object{
      Disk_Y
      scale <0,0.15>
    }
  }
  difference{
    object{
      Disk_X
      scale <0.5,0.2,0.2>
    }
    object{
      Disk_X
      scale <0.6,0.18,0.18>
    }
    translate <-1.2,0.4,0>
    pigment{color Green}
  }
  rotate <0,-80,0>
}