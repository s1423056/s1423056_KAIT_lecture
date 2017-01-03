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
		angle	35		
}
object	{
Cube
    translate z*1
		pigment	{	color	White	}
}