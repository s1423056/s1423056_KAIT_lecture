//導入ユニット　C言語　問題１　ポインタの理解１
//1423056　渡邉　翔　2014/12/19

#include <stdio.h>

int main(){
	int a = 0, b = 0, c = 0, d = 3000;

	printf("%8d: %d\n",&a,a);
	printf("%8d: %d\n",&b,b);
	printf("%8d: %d\n",&c,c);
	printf("%8d: %d\n",&d,d);
	printf("-----\n");
	a = 100;
	printf("%8d: %d\n",&a,a);
	printf("%8d: %d\n",&b,b);
    return 0;
}