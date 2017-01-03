//導入ユニット　C言語　問題7　繰り返しの応用
//1423056　渡邉　翔　2014/10/17

#include <stdio.h>

int main(){
	int num,loop1,loop2;
	printf("整数を入力：");
	scanf("%d",&num);

	for(loop1 = 0;loop1 < num;loop1++){
		for(loop2 = 0;loop2 < num-(loop1+1);loop2++){
			printf(" ");
		}
		for(loop2 = 0;loop2 <= loop1;loop2++){
			printf("*");
		}
		printf("\n");
	}

    return 0;
}