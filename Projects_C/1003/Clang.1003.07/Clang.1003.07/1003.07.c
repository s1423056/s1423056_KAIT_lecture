//�������j�b�g�@C����@���V�@�e�L�X�g�V�O�y�[�W�@�T���v��3�|�S����͂��A���s���Ȃ����B
//1423056�@�n糁@�ā@2014/10/03

#include <stdio.h>

int main(){
	int num1=1, num2=3;
	double dnum=3.14;

	printf("1��3������@: %f\n", 1/3);
	printf("1��3������A: %f\n", 1./3);
	printf("1��3������B: %f\n", 1/3.);

	printf("1��3������C: %f\n", num1/num2);
	printf("1��3������D: %f\n", (double)num1/num2);
	printf("1��3������E: %f\n", num1*1.0/num2);

	num1=dnum;
	num1=(int)dnum;

	return 0;
}