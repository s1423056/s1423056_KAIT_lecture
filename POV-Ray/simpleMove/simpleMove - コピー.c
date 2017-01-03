#include <stdio.h>
#include <string.h>
#include <math.h>

#define TOTAL_FRAME 90
#define FILENAME "simpleMove"
#define EXTEND ".pov"
#define PI  3.1415926

float lerp(float start, float end, float p);
float wavemove(float f,int t);

int main(){
	int loop;
	char str[256];
	for(loop = 0; loop < TOTAL_FRAME; loop++){
		FILE *fp;
		sprintf(str,"%s%d%s",FILENAME, loop, EXTEND);
		fp = fopen(str,"w");
		if(fp == NULL){
			printf("ファイルが開けません\n");
			return -1;
		}
		fprintf(fp,
			"\
			#include \"colors.inc\"\n \
			#include \"shapes.inc\"\n\
			\n\
			camera{\n\
				location <%d,100,-20>\n\
				look_at <%d,0,0>\n\
				angle 25\n\
			}        \n\
			\n\
			light_source{<2,5,-3> color White}\n\
			light_source{<-5,15,-30> color White}\n\
			\n\
			object{\n\
				Plane_XZ\n\
				pigment{checker color Black color White}\n\
				scale 10.0\n\
				translate<0,0,0>\n\
			}\n\
			\n\
			object{\n\
				Sphere\n\
				pigment{color rgb<%f,0,%f>}\n\
				translate<%d,0,%f>\n\
			}\n",
			loop,
			loop,
			(float)loop/TOTAL_FRAME,
			1.0f - (float)loop/TOTAL_FRAME,
			loop,
			wavemove(1.2f,loop)*5.0f);
		fclose(fp);
	}
	return 0;
}

float lerp(float start, float end, float p){
	float d = end - start;
	return start + d * p;
}

float wavemove(float f,int t){
	double tmp = PI*2/45*t;
	float y = sin(tmp)*f;
	return y;
}