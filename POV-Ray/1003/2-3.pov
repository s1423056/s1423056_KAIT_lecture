#include"colors.inc"
#include"shapes.inc"

camera{
  location<0,0,10>
  look_at<0,0,0>
  angle 60
}

light_source{ <-10,10,20> color White}
light_source{ <10,10,-10> color White}

object{
  Sphere
  pigment{ color Red }
  translate <-3,0,0>
}   
   
object{
  Sphere
  pigment{ color Magenta }
  translate <3,0,0>
}  

object{
  Sphere
  pigment{ color Green }
  translate <0,3,0>
}    

object{
  Sphere
  pigment{ color Yellow }
  translate <0,-3,0>
}   

object{
  Sphere
  pigment{ color Blue }
  translate <0,0,-3>
}