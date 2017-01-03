#include <stdio.h>

struct data{
	char name[50];
	int num;
	int grade;
};

int main(){
	int i;
	struct data d[10];
	for(i = 0; i < 10;i++){
		printf("%d人目のデータを入力します\n",i+1);
		printf("名前を入力してください:");
		scanf("%s",&d[i].name);
		printf("学籍番号を入力してください:");
		scanf("%s",&d[i].num);
		printf("学年を入力してください:");
		scanf("%s",&d[i].grade);
		printf("==============================\n");
	}
	printf("内容を出力\n");
	for(i = 0;i<10;i++){
		printf("名前：%s\n",d[i].name);
		printf("学籍番号：%d\n",d[i].num);
		printf("学年：%d\n\n",d[i].grade);
	}
	return 0;
}