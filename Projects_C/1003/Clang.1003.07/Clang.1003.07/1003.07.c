//導入ユニット　C言語　問題７　テキスト７０ページ　サンプル3−４を入力し、実行しなさい。
//1423056　渡邉　翔　2014/10/03

#include <stdio.h>

int main(){
	int num1=1, num2=3;
	double dnum=3.14;

	printf("1÷3をする�@: %f\n", 1/3);
	printf("1÷3をする�A: %f\n", 1./3);
	printf("1÷3をする�B: %f\n", 1/3.);

	printf("1÷3をする�C: %f\n", num1/num2);
	printf("1÷3をする�D: %f\n", (double)num1/num2);
	printf("1÷3をする�E: %f\n", num1*1.0/num2);

	num1=dnum;
	num1=(int)dnum;

	return 0;
}