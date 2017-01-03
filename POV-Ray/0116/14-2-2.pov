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
object	{	Cylinder_Y	scale	0.02	pigment{color Green}	}
object	{	Cylinder_Z	scale	0.02	pigment{color	Blue}	}
object	{
		prism	{
				conic_sweep
				linear_spline
				0,
				1,
				5,
				#declare	I=0;
				#while(I <	5)
						<cos(2*pi*I/5),sin(2*pi*I/5)>
						#declare	I	=	I+1;
				#end
				scale<1,-2,1>
				translate<0,2,0>
		}
		pigment	{color	Yellow}
}