//�������j�b�g�@C����@���T�@�e�L�X�g64�y�[�W�@�T���v��3�|2����͂��A���s���Ȃ����B
//1423056�@�n糁@�ā@2014/10/03

#include <stdio.h>

int main(){
	int num;
	double dnum;
	float fnum;

	printf("1.��������͂��Ă�������:");
	scanf("%d", &num);
	printf("2.��������͂��Ă�������:");
	scanf("%lf", &dnum);
	printf("3.��������͂��Ă�������:");
	scanf("%f", &fnum);

	printf("-���͂����l�̃��X�g-\n");
	printf("1:%d\n",num);
	printf("2:%.10f\n", dnum);
	printf("3:%.10f\n", fnum);
	return 0;
}