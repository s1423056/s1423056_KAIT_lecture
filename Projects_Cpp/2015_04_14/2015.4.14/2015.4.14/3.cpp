#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main(){
	double sec;
	clock_t t0;

	int moji;
	char roma[30];
	char hira[10];

	printf("Enter�L�[����������X�^�[�g���܂�\n");
	t0 = clock();

	sec = (double)(clock() - t0) / CLOCKS_PER_SEC;
	printf("�o�ߎ��Ԃ�%f�b�ł�\n",sec);

	return 0;
}