#include "colors.inc"
#include "shapes.inc" 
#include "textures.inc"
#include "Woods.inc"
#include "glass.inc"

camera{
  location < 0,10,-20>
  look_at <0,0,0>
  angle 25
}
light_source{<2,5,-3> color White}
light_source{<-5,15,-30> color White}   
 
object {
  Plane_XZ
  pigment{checker color White color Black}
  translate<0,-1,0>
}

object {
  Cone_Y
  scale <0.3,2.2,0.3>
  texture{T_Wood1}
  translate<0,1,0>
}

#declare T1 = 
texture{ 
  pigment{ 
    crackle metric 1 scale 0.5
    color_map{ 
      [0.0 color rgb<0.6,0.3,0.1>*0.8][0.3 White] 
    } 
  }
}

object{
  torus{1,0.2}
  texture{Pine_Wood}
  translate<0,(1-clock)*3-0.8,0.5>
  rotate<0,clock*540,0>
}
