//�������j�b�g�@C����@���1�@�v���O��������̗���
//1423056�@�n糁@�ā@2014/12/5

#include <stdio.h>

void inputAB(int *A, int *B){
	printf("Input num1:");		scanf("%d", &*A);
	printf("Input num2:");		scanf("%d", B);// ���scanf�Ƃ��Ȃ��Ӗ��ŗ��p�\
	return;
}

int main(){
	int aa = 0, bb = 1;
	printf("1:%d-%d\n",aa,bb);
	inputAB(&aa,&bb);
	printf("2:%d-%d\n",aa,bb);
    return 0;
}