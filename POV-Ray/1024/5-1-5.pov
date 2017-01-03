#include"colors.inc"
#include"shapes.inc"

camera{
  location<10,10,-10>
  look_at<0,0,0>
  angle 60
}

light_source{ <-10,10,20> color White }
light_source{ <10,10,-10> color White }
light_source{ <10,10,-100> color White }

background{color White}

#declare apple_seed = union{
  difference{
    object{
      Sphere
      scale 1
      pigment{ color Black }
    }
    object{
      Sphere
      scale 0.8
      pigment{ color White}
    }
  }
  object{
    Sphere
    scale 0.8
    pigment{ color White}
  }
  scale <0.5,1,0.2>
}

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
      apple_body
    } 
    object{
      Disk_Y
      translate <0,7.5,0>
      scale <0.5,0.7,0.5>
      pigment { color Red }
    }
    
    object{
      apple_seed
      rotate<0,0,-30>
      translate<1,0,0>
    }
    object{
      apple_seed
      rotate<0,0,30>
      translate<-1,0,0>
    }      
  }
  object{
    Cube
    translate <0,0,-1>
    scale 10
  }
  cutaway_textures
}
  
  