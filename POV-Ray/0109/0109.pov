#include	"colors.inc"
#include	"shapes.inc"
background	{	color	LightBlue	}
light_source	{
		<50,	100,	-100>
		color	White*1.5
		parallel	point_at	<0,	0,	0>
}
camera{
		location	<10.0,	10.0,	-15.0>
		look_at	<0.0,	0.0,	0.0>
		angle	35
}
//	X
object	{	
		Cylinder_X	
		scale	0.05	
		pigment{color	Red}
}
//	Y
object	{
		Cylinder_Y	
		scale	0.05	 
    pigment{color	Green}	
}
//	Z
object	{	
		Cylinder_Z	
		scale	0.05	
		pigment{color	Blue}	
}
#declare	I	=	0;
#while	(	I	<	6	)
		object	{
				Sphere	translate	5*x
				rotate	60*I*y
				pigment	{	color	Red	}
		}
#declare	I	=	I	+	1;
#end