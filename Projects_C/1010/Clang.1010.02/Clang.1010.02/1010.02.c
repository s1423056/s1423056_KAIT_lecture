//導入ユニット　C言語　問題2　奇数・偶数判定
//1423056　渡邉　翔　2014/10/10

#include <stdio.h>

int main(){
	int num;
	printf("整数を入力してください:");
	scanf("%d",&num);
	if(num >= 0){
		if(num % 2 == 0){
			printf("偶数\n");
		}else{
			printf("奇数\n");
		}
	}else{
		printf("不正入力\n");
	}
	return 0;
}