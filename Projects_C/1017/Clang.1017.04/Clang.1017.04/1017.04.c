//�������j�b�g�@C����@���4�@3�̒l�������ɕ��ёւ���
//1423056�@�n糁@�ā@2014/10/17

#include <stdio.h>

int main(){
	int pattern = 0;
	float num1,num2,num3;
	printf("1�ڎ������́F");
	scanf("%f",&num1);
	printf("2�ڎ������́F");
	scanf("%f",&num2);
	printf("3�ڎ������́F");
	scanf("%f",&num3);

	if(num1 < num2){
		if(num2 < num3){
			printf("%f\n",num1);
			printf("%f\n",num2);
			printf("%f\n",num3);
		}else{
			if(num1 < num3){
				printf("%f\n",num1);
				printf("%f\n",num3);
				printf("%f\n",num2);
			}else{
				printf("%f\n",num3);
				printf("%f\n",num1);
				printf("%f\n",num2);
			}
		}
	}else{
		if(num1 < num3){
			printf("%f\n",num2);
			printf("%f\n",num1);
			printf("%f\n",num3);
		}else{
			if(num3 < num2){
				printf("%f\n",num3);
				printf("%f\n",num2);
				printf("%f\n",num1);
			}else{
				printf("%f\n",num2);
				printf("%f\n",num3);
				printf("%f\n",num1);
			}
		}
	}
	return 0;
}