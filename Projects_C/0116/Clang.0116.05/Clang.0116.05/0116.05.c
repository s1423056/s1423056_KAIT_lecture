//導入ユニット　C言語　問題５　乱数の活用
//1423056　渡邉　翔　2014/1/16

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
	int n,l,num[200];
	FILE *fp;

	for(l = 100;l<200;l++)num[l] = 0;
	if((fp = fopen("data.csv","w")) == NULL){
		printf("ファイルが開けません\n");
		return 1;
	}
	srand((unsigned)time(NULL));
	for(l = 0;l<10000;l++){
		n = rand() % 100+100;
		printf("%d\n",n);
		num[n] += 1;
	}
	for(l = 100;l<200;l++){
		fprintf(fp,"%d,%d\n",l,num[l]);
	}
	fclose(fp);
    return 0;
}