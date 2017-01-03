//導入ユニット　C言語　問題6　素数判定
//1423056　渡邉　翔　2014/10/17

#include <stdio.h>

int main(){
	int num,check=0,loop;
	printf("自然数を入力：");
	scanf("%d",&num);

	while(num < 1){
		printf("値が不正です\n");
		printf("自然数を入力：");
		scanf("%d",&num);
	}
	for(loop = 2;loop<num/2+1;loop++){
		if(num%loop == 0) check = 1;
	}
	if(check == 1) printf("素数ではありません\n");
	else printf("素数です\n");
    return 0;
}