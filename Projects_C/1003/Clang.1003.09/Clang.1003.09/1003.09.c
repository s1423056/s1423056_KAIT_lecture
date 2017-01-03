//導入ユニット　C言語　問題９　テキスト73ページ　章末問題３を実施しなさい。
//1423056　渡邉　翔　2014/10/03
#include <stdio.h>

int main(){
	double num1,num2;

	printf("実数１を入力:");
	scanf("%lf",&num1);
	printf("実数２を入力:");
	scanf("%lf",&num2);
	printf("２つの実数の合計:%.3f\n",num1+num2);
	return 0;
}