#include	"colors.inc"
#include	"shapes.inc"
//	���� 1�A��ʂ̔��a 1 �̐� SIDES �p������� macro
#macro	PRISM(SIDES)
prism	{
				linear_sweep
				linear_spline
				0,	//	���ʂ̊J�n�ʒu
				1,	//	��ʂ̊J�n�ʒu
				SIDES, //	��ʂ̒��_��
				#local	I=0;
				#while	(I	<	SIDES)
						<cos(2*pi*I/SIDES),	sin(2*pi*I/SIDES)>
						#local	I	=	I+1;
				#end
		}
#end
//	���� 1�A��ʂ̔��a 1 �̐� SIDES �p������� macro
#macro	PYRAMID(SIDES)
		prism	{
				conic_sweep
				linear_spline
				0,	//	���ʂ̊J�n�ʒu
				1,	//	��ʂ̊J�n�ʒu
				SIDES, //	��ʂ̒��_��
				#local	I=0;
				#while	(I	<	SIDES)
						<cos(2*pi*I/SIDES),	sin(2*pi*I/SIDES)>
						#local	I	=	I+1;
				#end
				scale	<1,-1,1>
				translate	<0,1,0>
		}
#end
camera	{
		location	<5.0,	6.0, -8.0>
		look_at	<0.0,	0.0,	0.0>
		angle	35
}
background	{	color	LightBlue	}
object	{	Cylinder_X	scale	0.02	pigment{color	Red}	}
object	{	Cylinder_Y	scale	0.02	pigment{color	Green}	}
object	{	Cylinder_Z	scale	0.02	pigment{color	Blue}	}
#declare	I=0;
#while	(I	<	6)
		object	{
				#if(	mod(I,2)	=	0)
						PRISM(I+3)
				#else
						PYRAMID(I+3)
				#end
				pigment{color	Yellow}
				scale	<0.5,1.5,0.5>
				translate	<2,0,0>
				rotate	<0,60*I,0>
				#local	I=I+1;
		}
#end