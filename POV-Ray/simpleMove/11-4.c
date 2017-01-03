#include <stdio.h>
#include <string.h>

#define TOTAL_FRAME 90
#define FILENAME "simpleMove"
#define EXTEND ".pov"

float lerp(float start, float end, float p);

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
			#include \"colors.inc\"\n\
			#include \"shapes.inc\"\n\
			#include \"golds.inc\"\n\
			\n\
			camera{\n\
				location < 0,50,-100>\n\
				look_at <0,0,50>\n\
				angle 35\n\
			}\n\
			\n\
			light_source{<-3,50,-10> color White}\n\
			light_source{<5,90,-15> color 2.5*White}\n\
			\n\
			object {\n\
				Plane_XZ\n\
				pigment{checker color Red color Blue}\n\
				scale 10.0\n\
				translate<0,0,0>\n\
			}\n\
			\n\
			#declare FRAME_N = 90;\n\
			#declare V0 = 25;\n\
			#declare Angle = radians(85);\n\
			#declare Vx = V0*cos(Angle);\n\
			#declare Vy = V0*sin(Angle);\n\
			#declare g = 9.8;\n\
			#declare Time = 0.0;\n\
			#declare Tmax = 30;\n\
			#declare Time_interval = Tmax/FRAME_N;\n\
			#declare Nt = 2*Vy/g;\n\
			#declare Bt = 0.0;\n\
			#declare LoopMax = Tmax*clock + Time_interval/2;\n\
			#declare PosX = -Nt*Vx/2-10;\n\
			\n\
			#while(Time <= LoopMax)\n\
				#if(Time >= Nt)\n\
					#declare Vy = Vy*0.8;\n\
					#declare Bt = Nt;\n\
					#declare Nt = Nt+2*Vy/g;\n\
				#end\n\
					\n\
				#if((Time > Tmax*clock-Time_interval/2)&(Time<Tmax*clock+Time_interval/2))\n\
					object{\n\
						Sphere\n\
						texture{T_Gold_1A}\n\
						scale 3\n\
						#declare Ty = Vy*(Time-Bt)-g*(Time-Bt)*(Time-Bt)/2;\n\
						#if(Ty<0)\n\
							#declare Ty = 0;\n\
						#end\n\
						#declare Tx = Vx*Time+PosX;\n\
						translate<Tx,Ty,Tx>\n\
						translate<0,3,0>\n\
					}\n\
				#end\n\
				#declare Time = Time+Time_interval;\n\
			#end\n",
			lerp(-5.0f,5.0f,loop/(float)TOTAL_FRAME));
		fclose(fp);
	}
	return 0;
}

float lerp(float start, float end, float p){
	float d = end - start;
	return start + d * p;
}