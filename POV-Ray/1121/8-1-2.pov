#include	"colors.inc"
#include	"shapes.inc"   


light_source	{ <10, 10, -2> color	White }
light_source	{ <0, 0, -10> color	White }
light_source	{ <0, 10, 10> color	White }
		

camera{
		location	<10.0,	8.0, -16.0>		
		look_at	<0.0,	0.0, 0.0>				
		angle	35		
}

object	{
  Cube 
  scale 2.5
	pigment	{	
	  image_map{ jpeg "tex.jpeg" map_type 0 }
	}
	
	rotate y*90
}