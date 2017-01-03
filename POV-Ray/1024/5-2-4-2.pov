#include"colors.inc"
#include"shapes.inc"

camera{
  location<10,7.5,-10>
  look_at<0,0,0>
  angle 60
}

light_source{ <-10,10,20> color White }
light_source{ <10,10,-10> color White }
light_source{ <10,10,-100> color White }

background{color White}

#declare apple_body = union{
  difference{
    object{
      Sphere
      scale 5
      pigment{ color Red }
    }
    object{
      Sphere
      scale 4.5
      pigment{ color Flesh }
    }
  } 
  object{
    Sphere
    scale 4.5
    pigment{ color Flesh }
  }
}  
  difference{
    union{
      object{
        Disk_Y
        translate <0,7.5,0>
        scale <0.5,0.7,0.5>
        pigment { color Red }
      } 
      object{
        apple_body
      }      
    }
    object{
      Cube
      translate <0,0,-1>
      scale 10
    }
    cutaway_textures
  }
