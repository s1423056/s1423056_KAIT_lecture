//導入ユニット　C言語　問題6　食塩水の問題
//1423056　渡邉　翔　2014/12/5

#include <stdio.h>

void syokuen(int a, int b, int c, int d,int *per, int *gram){
	float syokuen1,syokuen2;
	syokuen1 = (c*100.0f)/a;
	syokuen2 = (d*100.0f)/b;
	*gram = a+b;
	*per = ((syokuen1+syokuen2)/(a+b))*100;
	return;
}
int main(){
	int A = 100,B = 120,C = 21,D = 18;
	int p,g;
	syokuen(A,B,C,D,&p,&g);
	printf("%d％の食塩水が%dグラム\n",p,g);
    return 0;
}