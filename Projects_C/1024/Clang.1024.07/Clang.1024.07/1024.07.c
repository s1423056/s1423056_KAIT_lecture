//導入ユニット　C言語　問題7　素数をリストアップ
//1423056　渡邉　翔　2014/10/24

#include <stdio.h>

int main(){
	int num,num2 = 2,check = 0,loop,count=0;
	printf("リストアップする素数の数を入力：");
	scanf("%d",&num);

	while(count < num){
		for(loop = 2; loop < num2 / 2 + 1; loop++){
			if(num2 % loop == 0) check = 1;
		}
		if(check == 1) check = 0;
		else{
			printf("%d\n",num2);
			count++;
		}
		num2++;
	}
    return 0;
}