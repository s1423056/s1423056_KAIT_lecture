//導入ユニット　C言語　問題3　ポインタの理解3
//1423056　渡邉　翔　2014/12/19

#include <stdio.h>

int main(){
	int AA,BB;
	int *tmp;
	int *adr1 = &AA;
	int *adr2;
	adr2 = &BB;

	AA = 3; BB = 5;
	printf("1:%3d[%8d] - %3d[%8d]\n", AA, &AA, BB, &BB);
	printf("2:%3d[%8d] - %3d[%8d]\n", *adr1, adr1, *adr2, adr2);

	tmp = adr2;
	adr2 = adr1;
	adr1 = tmp;

	printf("1:%3d[%8d] - %3d[%8d]\n", AA, &AA, BB, &BB);
	printf("2:%3d[%8d] - %3d[%8d]\n", *adr1, adr1, *adr2, adr2);
    return 0;
}