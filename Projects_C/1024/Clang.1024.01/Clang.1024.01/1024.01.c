//導入ユニット　C言語　問題1　復習(表示・繰り返し・条件分岐)
//1423056　渡邉　翔　2014/10/24

#include <stdio.h>

int main(){
	int num,x,y;
	printf("3以上40以下の整数:");
	scanf("%d",&num);
	for(x = 0;x<num;++x){
		for(y=0;y<num;++y){
			if(x==0||y==0||x==(num-1)||y==(num-1))printf("*");
			else printf(" ");
		}
		printf("\n");
	}
    return 0;
}