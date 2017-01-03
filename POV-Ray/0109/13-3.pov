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
//	X Ž²
object	{	
		Cylinder_X	
		scale	0.05	
		pigment{color	Red}
}
//	Y Ž²
object	{
		Cylinder_Y	
		scale	0.05	
		pigment{color	Green}	
}
//	Z Ž²
object	{	
		Cylinder_Z	
		scale	0.05	
		pigment{color	Blue}	
}
#declare	S1	=	seed(2015);
#declare	I=0;
#while	(	I	<	12	)
object	{
		Sphere	translate	<(6-3)*rand(S1)+3,0,0>
		translate	<0,	2*rand(S1),	0.0>
		rotate	<0,I*30,0>
		pigment	{	color	Red	}
}
#declare	I	=	I	+	1;
#end