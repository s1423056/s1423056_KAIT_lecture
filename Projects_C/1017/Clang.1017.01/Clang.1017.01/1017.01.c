//導入ユニット　C言語　問題1　10個の変数を利用して値を記憶し、平均値を求める
//1423056　渡邉　翔　2014/10/17

#include <stdio.h>

int main(){
	int num,i;
	float all = 0;
	for(i = 1;i<=10;i++){
		printf("%d回目整数を入力：",i);
		scanf("%d",&num);
		all=all+num;
	}
	all=all/10.0;
	printf("平均は：%f\n",all);
    return 0;
}