//導入ユニット　C言語　問題6　テキスト６７ページ　サンプル3－3を入力し、実行しなさい。
//1423056　渡邉　翔　2014/10/03

#include <stdio.h>

int main(){
	int num=0;
	printf("%d\n", num);
	printf("%d\n", num++);
	printf("%d\n", num);

	printf("-----\n");
	num=0;
	printf("%d\n", num);
	printf("%d\n", ++num);
	printf("%d\n", num);

	printf("-----\n");
	printf("%d\n", 4/2);
	printf("%d\n", 5/2);
	printf("%d\n", 4/10);
	printf("%d\n", 9/10);

	printf("-----\n");
	printf("%f\n", 1/3);
	printf("%f\n", 1.0/3.0);
	printf("%f\n", 1.0/3);
	printf("%f\n", 1./3.);
	return 0;
}