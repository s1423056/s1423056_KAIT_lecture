//導入ユニット　C言語　問題3　分散を求める
//1423056　渡邉　翔　2014/10/17

#include <stdio.h>

int main(){
	int num1,num2,num3,num4;
	float all,var;
		printf("1回目整数を入力：");
		scanf("%d",&num1);
		printf("2回目整数を入力：");
		scanf("%d",&num2);
		printf("3回目整数を入力：");
		scanf("%d",&num3);
		printf("4回目整数を入力：");
		scanf("%d",&num4);

	all = (num1+num2+num3+num4)/4.0;
	var = ((num1 - all)*(num1 - all)+(num2 - all)*(num2 - all)+(num3 - all)*(num3 - all)+(num4 - all)*(num4 - all))/4;

	printf("平均は：%f\n",all);
	printf("分散は：%f\n",var);
    return 0;
}