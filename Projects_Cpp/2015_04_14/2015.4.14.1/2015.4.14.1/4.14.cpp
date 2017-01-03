#include <stdio.h>

int main(){
	char name[81];
	char rate = 'X';
	int score;
	printf("名前を入力してください：");
	scanf("%s",name);
	printf("点数を入力してください：");
	scanf("%d",&score);
	if(score >100 || score < 0) rate = 'X';
	else if(score < 60) rate = 'D';
	else if(score < 70) rate = 'C';
	else if(score < 80) rate = 'B';
	else if(score < 90) rate = 'A';
	else rate = 'S';
	printf("%sさんの評価は%cです。\n",name,rate);
	return 0;
}