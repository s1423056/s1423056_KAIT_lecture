#include	"colors.inc"
#include	"shapes.inc"
camera{
		location	<1,0.5,-15>
		look_at	<1,0.5,0>
		angle	30
}
light_source{	<2,2,-4>	color	White}
light_source{	<-2,2,-4>	color	White}
text{
		ttf	"Arial.ttf",										
		"1423056",																
		1,																		
		0																								
		pigment{color	rgb<0,0,0.9>}
		translate<-1,0,0>
}
text{                                 
		ttf	"Arial.ttf",										
		"watanabe syou",																
		1,																		
		0																								
		pigment{color	rgb<0,0,0.9>}
		translate<-2,-1,0>
}

background{color	White}