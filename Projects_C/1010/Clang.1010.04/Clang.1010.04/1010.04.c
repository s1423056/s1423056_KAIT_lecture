//導入ユニット　C言語　問題4　二重繰り返し処理を利用した九九の表作成
//1423056　渡邉　翔　2014/10/10

#include <stdio.h>

int main(){
	int x,y;
	printf("10x19\n");

	for(y = 10; y <= 19; y++){
		for(x = 10; x <= 19; x++){
			printf("%4d",x*y);
		}
		printf("\n");
	}
	return 0;
}