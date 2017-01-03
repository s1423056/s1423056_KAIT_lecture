#include "colors.inc"
#include "shapes.inc"
#include "skies.inc"

camera{
  location <0,20,-120>
  look_at <0,0,0>
  angle 40
}

light_source{z*2 color White parallel}
light_source{y*2 color White parallel}

sky_sphere{S_Cloud1}

object{Plane_XZ pigment{color Feldspar}}

#declare S1 = seed(1423056);
#declare field_X = 20;
#declare field_Z = 20;

#declare fx = -field_X;
#while(fx < field_X)
  #declare fz = -field_Z;
  #while(fz < field_Z)
    object{
      Cone_Y
      rotate <(rand(S1)*2-1)*10,0,(rand(S1)*2-1)*10>
      scale<0.5,4,0.5>
      pigment{color ForestGreen}
      translate<fx+rand(S1),-rand(S1),fz+rand(S1)>
    }
  #declare fz = fz+0.5;
  #end
#declare fx = fx+1;
#end