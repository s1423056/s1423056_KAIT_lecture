     #include	"colors.inc"
#include	"shapes.inc"
light_source	{
<500,	600,	-800>
color	White*2
parallel	point_at	<0,	0,	0>
}
camera	{
location	<5.0,	6.0,	-8.0>
look_at	<0.0,	0.0,	0.0>
angle	35
}
background	{	color	LightBlue	}
object	{	Cylinder_X	scale	0.02	pigment{color	Red}	}
object	{	Cylinder_Y	scale	0.02	pigment{color	Green}	}
object	{	Cylinder_Z	scale 0.02	pigment{color	Blue}	}
object	{
		prism	{
				linear_sweep
				linear_spline
				0,
				1,
				8,
				#declare	I=0;
				#while(I	<	8)
						<cos(2*pi*I/8),sin(2*pi*I/8)>
						#declare	I	=	I+1;
				#end
						}
		pigment	{color	Yellow}
		scale	<1,2,1>
}