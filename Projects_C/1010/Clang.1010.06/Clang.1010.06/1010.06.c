//�������j�b�g�@C����@���U�@���������͂�����܂ŌJ��Ԃ�
//1423056�@�n糁@�ā@2014/10/10

#include <stdio.h>

int main(){
	int num = 0;
	printf("1����10�܂ł̐����𑫂�������?\n");
	printf("���̐����P�`�T�őI��\n");
	printf("1:40,2:45,3:50,4:55,5:60\n");
	scanf("%d",&num);
	while(num != 4){
		printf("�s����\n������x���͂��Ă��������B\n");
		scanf("%d",&num);
	}
	printf("����\n");
	num = 0;
	printf("10�~10�̓����́H");
	printf("���̐����P�`�T�őI��\n");
	printf("1:1,2:10,3:100,4:1000,5:10000\n");
	scanf("%d",&num);
	while(num != 3){
		printf("�s����\n������x���͂��Ă��������B\n");
		scanf("%d",&num);
	}
	printf("����\n");
	
	return 0;

}