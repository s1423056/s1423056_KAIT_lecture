#include <stdio.h>

int main(){
	int val[11]={0};
	int num;
	int i;
	printf("数字の0~9を10回入力してください\n");
	for(i=0;i<10;i++){
		scanf("%d",&num);
		if(num < 0||num > 9)val[10]++;
		else val[num]++;
	}
	for(i=0;i<10;i++){
		printf("%dが%d回入力されました\n",i,val[i]);
	}
	printf("0〜9以外の数字が%d回入力されました\n",val[10]);
	return 0;
}