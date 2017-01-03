//導入ユニット　C言語　問題1　プログラム動作の理解
//1423056　渡邉　翔　2014/12/5

#include <stdio.h>

void inputAB(int *A, int *B){
	printf("Input num1:");		scanf("%d", &*A);
	printf("Input num2:");		scanf("%d", B);// 上のscanfとおなじ意味で利用可能
	return;
}

int main(){
	int aa = 0, bb = 1;
	printf("1:%d-%d\n",aa,bb);
	inputAB(&aa,&bb);
	printf("2:%d-%d\n",aa,bb);
    return 0;
}