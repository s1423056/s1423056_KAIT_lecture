#include "colors.inc"
camera{
 location <0,0,-12>
 look_at <0,0,0>
 angle 30
}
light_source{ <8,0,-15> color White}
light_source{ <-8,0,-15> color White}

blob{
 threshold 0.5
 sphere{<0,1,0>,1.5,1}
 sphere{<0,-1,0>,1.5,2}    
 pigment{color Red}
}