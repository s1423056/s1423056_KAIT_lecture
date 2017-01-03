#include "Colors.inc"
#include "Shapes.inc"
#include "Woods.inc"
#include "textures.inc"

camera{
  location <40,10,120>
  look_at <0,2,0>
  angle 40
}

light_source{z*2 color White parallel}

object{Plane_XZ pigment{color Green}}

#declare yane_ue =
union{
  difference{
    object{
      prism{
        linear_sweep
        -1,
        1,
        3
        <cos(0),sin(0)>,
        <cos(pi),sin(pi)>,
        <cos(pi/2),sin(pi/2)>*3
        rotate z*90
        rotate x*-90
        scale<4,1,3>
        texture{DMFWood5}
      }
    }
    #declare c = -1;
    #while (c < 2)
      object{
        prism{
          linear_sweep
          -1,
          1,
          3
          <cos(0),sin(0)>,
          <cos(pi),sin(pi)>,
          <cos(pi/2),sin(pi/2)>*3
          rotate z*90
          rotate x*-90
          scale<2,1,3>*1.2
          translate<-6*c,-1,0>
        }
      }
    #declare c = c+1;
    #end
    cutaway_textures
  }
  
  object{
    sphere_sweep{
      linear_spline
      2,
      <-4,2.8,0>,0.2
      <4,2.8,0>,0.2
      texture{DMFWood5}
    }
  }
}

#declare yane_sita =
object{
  prism{
    conic_sweep
    linear_spline
    15,
    26,
    4,
    <-4/3,-1>,<-4/3,1>,<4/3,1>,<4/3,-1>
  }
  texture{DMFWood5}
  scale y*-1
  translate y*25
}

#declare yane = 
union{
  object{
    yane_ue
    scale 5
    translate y*10
  }
  object{
    yane_sita
  }
  object{
    yane_ue
    scale 4.5
    translate y*2
    scale x*1.2
    rotate y*90
  }
}

object{yane}