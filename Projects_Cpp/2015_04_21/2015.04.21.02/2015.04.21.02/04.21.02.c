#include <stdio.h>

struct data{
	char name[50];
	int num;
	int grade;
};

int main(){
	int i;
	struct data d[10];
	for(i = 0; i < 10;i++){
		printf("%d�l�ڂ̃f�[�^����͂��܂�\n",i+1);
		printf("���O����͂��Ă�������:");
		scanf("%s",&d[i].name);
		printf("�w�Дԍ�����͂��Ă�������:");
		scanf("%s",&d[i].num);
		printf("�w�N����͂��Ă�������:");
		scanf("%s",&d[i].grade);
		printf("==============================\n");
	}
	printf("���e���o��\n");
	for(i = 0;i<10;i++){
		printf("���O�F%s\n",d[i].name);
		printf("�w�Дԍ��F%d\n",d[i].num);
		printf("�w�N�F%d\n\n",d[i].grade);
	}
	return 0;
}