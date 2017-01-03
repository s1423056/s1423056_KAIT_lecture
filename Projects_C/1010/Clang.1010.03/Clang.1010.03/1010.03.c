//導入ユニット　C言語　問題3　繰り返し処理の確認
//1423056　渡邉　翔　2014/10/10

#include <stdio.h>

int main(){
	int num1,num2,i;
	printf("数値を入力（1つ目の数値は2つ目より小さく）\n");
	scanf("%d%d",&num1,&num2);
	if(num1 >= num2) return 0;

	for(i = num1;i <= num2;i++){
		if(i%2==0)printf("%d\n",i);
	}
	return 0;
}