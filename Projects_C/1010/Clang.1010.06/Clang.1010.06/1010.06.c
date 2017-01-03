//導入ユニット　C言語　問題６　正しい入力があるまで繰り返す
//1423056　渡邉　翔　2014/10/10

#include <stdio.h>

int main(){
	int num = 0;
	printf("1から10までの整数を足した数は?\n");
	printf("次の数字１～５で選べ\n");
	printf("1:40,2:45,3:50,4:55,5:60\n");
	scanf("%d",&num);
	while(num != 4){
		printf("不正解\nもう一度入力してください。\n");
		scanf("%d",&num);
	}
	printf("正解\n");
	num = 0;
	printf("10×10の答えは？");
	printf("次の数字１～５で選べ\n");
	printf("1:1,2:10,3:100,4:1000,5:10000\n");
	scanf("%d",&num);
	while(num != 3){
		printf("不正解\nもう一度入力してください。\n");
		scanf("%d",&num);
	}
	printf("正解\n");
	
	return 0;

}