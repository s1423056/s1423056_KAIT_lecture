#include <stdio.h>
#include <math.h>

double hen[3];

double menseki(double a, double b, double c){
	double s = (a+b+c)/2.0;
	return sqrt(s*(s-a)*(s-b)*(s-c));
}

int main(){
	int i;
	printf("�O�p�`��3�ӂ̒�������͂��Ă��������B:");
	scanf("%lf",&hen[0]);
	scanf("%lf",&hen[1]);
	scanf("%lf",&hen[2]);
	printf( "�ʐς�%f�ł��B\n", menseki(hen[0],hen[1],hen[2]) );
	return 0;
}

