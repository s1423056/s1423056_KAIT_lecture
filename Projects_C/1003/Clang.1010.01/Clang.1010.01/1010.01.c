//導入ユニット　C言語　問題１ if elseの使い方確認
//1423056　渡邉　翔　2014/10/10

#include <stdio.h>

int main(){
	int num = 0;
	printf("1から10までの整数を足した数は?\n");
	printf("次の数字１～５で選べ\n");
	printf("1:40,2:45,3:50,4:55,5:60\n");
	scanf("%d",&num);
	if(num == 4){
		printf("正解\n");
	}else{
		printf("不正解\n");
	}
	return 0;
}