#include"colors.inc"
#include"shapes.inc"

camera{
  location<15,30,45>
  look_at<0,0,0>
  angle 30
}

light_source{ <15,0,15> color White }
light_source{ <0,15,0> color White }
light_source{ <-8,15,0> color White }
light_source{ <-8,15,10> color White }

object{
  Plane_XZ
  translate<0,-5,0>
  pigment{
    checker
    color Black, color White
    scale 5
  }
}

difference{
  object{
    Cube
    pigment{
    brick 
    color White ,color Brown
    scale 1/10
    }
  }    
  object{
    Cube
    translate<1,1,1>
  }
  scale 5
  translate<5,0,0>
  #cutaway_textures
}

object{
  Sphere  
  scale 5
  pigment{
    hexagon
    color Blue,Red,Green
    scale 0.8
  }
  rotate x*-90
  translate<-10,0,0>
}