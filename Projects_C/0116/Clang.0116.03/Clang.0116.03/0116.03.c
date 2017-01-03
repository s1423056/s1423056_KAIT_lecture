//導入ユニット　C言語　問題３　構造体を使ってプログラムを構築する
//1423056　渡邉　翔　2014/1/16

#include <stdio.h>

typedef struct data{
	char name[32];
	int koku,suu,ei,ri,sya;
}DATA;

int main(){
	int loop;
	DATA data[20];
	FILE *fp;
 
	if((fp = fopen("data.txt","w")) == NULL){
		printf("ファイルの作成に失敗しました\n");
		return 1;
	}
	for(loop = 0;loop<20;loop++){
		printf("%2d\n",loop+1);
		printf("名前：");scanf("%s",data[loop].name);
		printf("国語：");scanf("%d",&data[loop].koku);
		printf("数学：");scanf("%d",&data[loop].suu);
		printf("英語：");scanf("%d",&data[loop].ei);
		printf("理科：");scanf("%d",&data[loop].ri);
		printf("社会：");scanf("%d",&data[loop].sya);
		printf("============================\n");
		fprintf(fp,"名前：%s\n",data[loop].name);
		fprintf(fp,"国語：%d\n",data[loop].koku);
		fprintf(fp,"数学：%d\n",data[loop].suu);
		fprintf(fp,"英語：%d\n",data[loop].ei);
		fprintf(fp,"理科：%d\n",data[loop].ri);
		fprintf(fp,"社会：%d\n",data[loop].sya);
		fprintf(fp,"============================\n");
	}
	fclose(fp);
    return 0;
}