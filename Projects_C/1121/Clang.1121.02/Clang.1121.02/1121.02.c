//導入ユニット　C言語　問題2
//1423056　渡邉　翔　2014/11/21

#include <stdio.h>

int main(){
	int loop;
	char moji[81];
	scanf("%s",moji);
	for(loop = 1;loop < 81;loop++){
		printf("%c",moji[loop-1]);
		if(loop%10 == 0) printf("\n");
	}
	printf("\n");
    return 0;
}