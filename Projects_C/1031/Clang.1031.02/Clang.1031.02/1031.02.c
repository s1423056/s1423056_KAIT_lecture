//導入ユニット　C言語　問題2　ファイルへの出力
//1423056　渡邉　翔　2014/10/31

#include <stdio.h>

int main(){
	FILE *fp;
	int num,month,day,all;
	if((fp = fopen("log1.txt","r")) == NULL){
		printf("ファイルが開けません。\n");
		return 1;
	}
	if((fp = fopen("log1.txt","w")) == NULL){
		printf("ファイルが開けません。\n");
		return 1;
	}
	printf("学籍番号：");
	scanf("%d",&num);
	printf("誕生月：");
	scanf("%d",&month);
	printf("誕生日：");
	scanf("%d",&day);
	all = month*100+day;
	fprintf(fp,"%d\n",num);
	fprintf(fp,"%d\n",all);
	printf("学籍番号%d\n",num);
	printf("誕生月日%d\n",all);
	fclose(fp);
    return 0;
}