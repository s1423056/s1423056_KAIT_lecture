//�������j�b�g�@C����@���2�@��E��������
//1423056�@�n糁@�ā@2014/10/10

#include <stdio.h>

int main(){
	int num;
	printf("��������͂��Ă�������:");
	scanf("%d",&num);
	if(num >= 0){
		if(num % 2 == 0){
			printf("����\n");
		}else{
			printf("�\n");
		}
	}else{
		printf("�s������\n");
	}
	return 0;
}