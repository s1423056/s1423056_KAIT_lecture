//導入ユニット　C言語　問題1　プログラム実行カウンタの作成
//1423056　渡邉　翔　2014/10/31

#include <stdio.h>

int main(){
	FILE *FP;
	int num;
	if((FP = fopen("log.txt","r")) == NULL){
		printf("初めての実行\n");
		num = 1;
	}else{
		fscanf(FP,"%d",&num);
		num++;
		printf("%d回目の実行\n",num);
		fclose(FP);
	}
	if((FP = fopen("log.txt","w")) == NULL){
		printf("Fileを開けません\n");
		return(1);
	}
	fprintf(FP,"%d",num);
	fclose(FP);
	return (0);

}