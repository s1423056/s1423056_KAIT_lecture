//�������j�b�g�@C����@���3�@�J��Ԃ������̊m�F
//1423056�@�n糁@�ā@2014/10/10

#include <stdio.h>

int main(){
	int num1,num2,i;
	printf("���l����́i1�ڂ̐��l��2�ڂ�菬�����j\n");
	scanf("%d%d",&num1,&num2);
	if(num1 >= num2) return 0;

	for(i = num1;i <= num2;i++){
		if(i%2==0)printf("%d\n",i);
	}
	return 0;
}