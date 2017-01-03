//導入ユニット　C言語　問題５　テキスト64ページ　サンプル3－2を入力し、実行しなさい。
//1423056　渡邉　翔　2014/10/03

#include <stdio.h>

int main(){
	int num;
	double dnum;
	float fnum;

	printf("1.整数を入力してください:");
	scanf("%d", &num);
	printf("2.実数を入力してください:");
	scanf("%lf", &dnum);
	printf("3.実数を入力してください:");
	scanf("%f", &fnum);

	printf("-入力した値のリスト-\n");
	printf("1:%d\n",num);
	printf("2:%.10f\n", dnum);
	printf("3:%.10f\n", fnum);
	return 0;
}