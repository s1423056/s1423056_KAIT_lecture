//導入ユニット　C言語　問題3　テキスト46ページ　サンプル2－4を入力し、実行しなさい。
//1423056　渡邉　翔　2014/10/03

#include <stdio.h>

int main(){
	int number;
	double dnumber;

	number=3;
	dnumber=3.14;

	printf("1: number=%d\n", number);
	printf("1: dnumber=%f\n", dnumber);

	number = number+2;
	printf("2: number=%d\n", number);

	number=10/5;
	printf("3: number=%d\n", number*2);
	printf("4: numver=%d\n", number);
	return 0;
}