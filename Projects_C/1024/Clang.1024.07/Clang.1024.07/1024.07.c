//�������j�b�g�@C����@���7�@�f�������X�g�A�b�v
//1423056�@�n糁@�ā@2014/10/24

#include <stdio.h>

int main(){
	int num,num2 = 2,check = 0,loop,count=0;
	printf("���X�g�A�b�v����f���̐�����́F");
	scanf("%d",&num);

	while(count < num){
		for(loop = 2; loop < num2 / 2 + 1; loop++){
			if(num2 % loop == 0) check = 1;
		}
		if(check == 1) check = 0;
		else{
			printf("%d\n",num2);
			count++;
		}
		num2++;
	}
    return 0;
}