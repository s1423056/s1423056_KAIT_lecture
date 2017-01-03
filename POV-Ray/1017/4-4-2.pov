#include "colors.inc"
#include "shapes.inc"

camera{
  location <0,2,-5>
  look_at <0,0,0>
}

light_source{<0,10,-10> color White}                 
light_source{<0,10,0> color White}
      
difference{
  difference{
    union{
      difference{
        object{
          Disk_Y
          scale <1,0.9,1>
          pigment {color Cyan}
        }
        object{
          Disk_Y
          scale <0.9,0.91,0.9>
          translate <0,0.15,0>
          pigment {color Yellow}
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
      rotate <0,0,0>
    }
    object{
      Cube     
      scale <2,2,2>
      rotate <0,0,0>
      translate <0,0,-2>
      pigment {color Yellow}
    }
  }
  object{
    Disk_X
    scale <1,0.2,0.2>
    translate <-1,0.4,0>
    pigment {color Cyan}
  }
  object{
    Disk_Y
    scale <0.9,0.91,0.9>
    translate <0,0.15,0>
    pigment {color Yellow}
  }
}