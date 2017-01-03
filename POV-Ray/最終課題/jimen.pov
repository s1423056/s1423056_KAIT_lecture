#include "colors.inc"
#include "shapes.inc"
#include "skies.inc"

camera{
  location <0,20,-50>
  look_at <0,0,0>
  angle 40
}

light_source{z*2 color White parallel}
light_source{y*2 color White parallel}

sky_sphere{S_Cloud1}

object{Plane_XZ pigment{color Feldspar}}

#macro kusa(sFieldX,sFieldZ,eFieldX,eFieldZ)
  #local S1 = seed(1423056);
  
  #local fx = sFieldX;
  #while(fx < eFieldX)
    #local fz = sFieldZ;
    #while(fz < eFieldZ)
      object{
        Cone_Y
        rotate <(rand(S1)*2-1)*10,0,(rand(S1)*2-1)*10>
        scale<rand(S1)*0.1+0.4,rand(S1)+3,rand(S1)*0.1+0.4>
        pigment{color ForestGreen}
        translate<fx+rand(S1),-rand(S1),fz+rand(S1)>
      }
    #local fz = fz+0.4;
    #end
  #local fx = fx+1;
  #end
#end

kusa(-20,0,20,10)