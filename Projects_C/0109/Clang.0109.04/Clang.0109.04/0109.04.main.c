//�������j�b�g�@C����@���4�@�����t�@�C���Ŏ��s�v���O�������쐬����
//1423056�@�n糁@�ā@2014/1/9
#include "0109.04.mydef.h"

//���̊֐��ŌĂяo���v���g�^�C�v�錾
int printALL(DTYPE data[], int Dnum);
int inputData(DTYPE data[], int *Dnum);

int main(){
	DTYPE data[DATANUM];
	int Dnum = 0;
	inputData(data, &Dnum); printALL(data, Dnum);
	printf("\n==Now Dnum=%d\n\n", Dnum);
	inputData(data, &Dnum); printALL(data, Dnum);
	return 0;
}