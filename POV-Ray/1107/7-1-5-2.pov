#include	"colors.inc"
#include	"shapes.inc"
object	{	Cylinder_X	scale	0.02	pigment{color	Red}	}				//	(a)
object	{	Cylinder_Y	scale	0.02	pigment{color	Green}	}		  //	(b)
object	{	Cylinder_Z	scale	0.02	pigment{color	Blue}	}			  //	(c)
background	{	color	LightBlue	}
light_source	{
		<500,	800,	-600>						
		color	White*2
		parallel	point_at	<0,	0,	0>
}
camera{
		location	<5.0,	6.0,	-8.0>		
		look_at	<0.0,	0.0,	0.0>				
		angle	60		
}

# declare Haizara =
difference{
  object{ 
    Disk_Y
    scale <3,0.75,3>
    translate <0,-1,0>
  }
  object{
    Disk_Y
    scale <2.8,1,2.8>
    translate <0,-0.3,0>
  }
  object{
    Disk_Z
    scale <0.3,0.3,2>
    translate <0,-0.2,2>
  }
  object{
    Disk_Z
    scale <0.3,0.3,2>
    translate <0,-0.2,2>
    rotate 90*1*y
  }
  object{
    Disk_Z
    scale <0.3,0.3,2>
    translate <0,-0.2,2>
    rotate 90*2*y
  }
  object{
    Disk_Z
    scale <0.3,0.3,2>
    translate <0,-0.2,2>
    rotate 90*3*y
  }
  
  pigment {color Gray}
}

object{
  Haizara
  translate <0,1,0>
}