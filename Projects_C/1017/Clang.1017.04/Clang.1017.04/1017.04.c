//導入ユニット　C言語　問題4　3個の値を昇順に並び替える
//1423056　渡邉　翔　2014/10/17

#include <stdio.h>

int main(){
	int pattern = 0;
	float num1,num2,num3;
	printf("1個目実数入力：");
	scanf("%f",&num1);
	printf("2個目実数入力：");
	scanf("%f",&num2);
	printf("3個目実数入力：");
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