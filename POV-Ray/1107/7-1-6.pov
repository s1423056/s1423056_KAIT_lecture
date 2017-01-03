#include	"colors.inc"
#include	"shapes.inc"

background	{	color	White	}

light_source	{
		<5,	8, 6>						
		color	White*3
		parallel	point_at	<0,	0,	0>
}

camera{
		location	<-5.0, 5.0, 8.0>		
		look_at	<0.0,	0.0, 0.0>				
		angle	60		
}
difference{
  object{
    Cube
    scale 2
    pigment{color Red}
  }
  
  object{
    Cube
    scale 1.3
    translate z*-1
    pigment{color Red}
  }
  object{
    Cube
    scale 1.5
    translate z*1
    pigment{color Red}
  }
  object{
    Cube
    scale 1.5
    translate y*1
    pigment{color Red}
  }
  object{
    Cube
    scale 1.5
    translate y*-1
    pigment{color Red}
  }
  object{
    Cube
    scale 1.5
    translate x*1
    pigment{color Red}
  }
  object{
    Cube
    scale 1.5
    translate x*-1
    pigment{color Red}
  }
}   