//導入ユニット　C言語　問題2　ポインタの理解2
//1423056　渡邉　翔　2014/12/19

#include <stdio.h>

int main(){
	int data[3] ={0,1,2};
	double DA[3] = {3.0,3.1,3.2};
	printf("%d\t[%d]\n", &data[0], data[0]);
	printf("%d\t[%d]\n", &data[1], data[1]);
	printf("%d\t[%d]\n", &data[2], data[2]);
	printf("----------\n");
	printf("%d\t[%f]\n", &DA[0], DA[0]);
	printf("%d\t[%f]\n", &DA[1], DA[1]);
	printf("%d\t[%f]\n", &DA[2], DA[2]);
	printf("----------\n");
	printf("+0[%d]\n",*( (&data[0])+0) );
	printf("+1[%d]\n",*( (&data[0])+1) );
	printf("+2[%d]\n",*( (&data[0])+2) );
	printf("+0[%f]\n",*( (&DA[0])+0) );
	printf("+1[%f]\n",*( (&DA[0])+1) );
	printf("+2[%f]\n",*( (&DA[0])+2) );
    return 0;
}