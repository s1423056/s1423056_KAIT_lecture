//導入ユニット　C言語　問題4　ファイルから数値の読み取り
//1423056　渡邉　翔　2014/10/31

#include <stdio.h>

int main(){
	FILE *fp;
	int num = 0,month = 0,day = 0,all = 0;
	if((fp = fopen("log1.txt","r")) == NULL){
		printf("ファイルを開けません。\n");
		return 1;
	}

	fscanf(fp,"%d",&num);
	printf("学籍番号：%d\n",num);

	fscanf(fp,"%d",&all);
	month = all /100;
	day = all-(month*100);
	printf("誕生日：%d月　%d日\n",month,day);
	fclose(fp);
    return 0;
}