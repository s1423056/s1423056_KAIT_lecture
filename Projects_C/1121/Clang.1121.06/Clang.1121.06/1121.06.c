//導入ユニット　C言語　問題6　strlen()の利用
//1423056　渡邉　翔　2014/11/21

#include <stdio.h>
#include <string.h>

int main(){
	FILE *FP;
	char input[81];
	int hindo[16] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	int loop;

	if((FP = fopen("input3.txt","r")) == NULL){
		printf("File Open Error\n");
		return 1;
	}

	while(fscanf(FP,"%s",input) != EOF){
		hindo[strlen(input)] += 1;
		hindo[0] +=1;
	}

	for(loop = 1;loop<16;loop++){
		if(hindo[loop] != 0)printf("%d文字の単語： %d単語\n",loop,hindo[loop]);
	}
	printf("全　%d単語\n",hindo[0]);
	fclose(FP);
    return 0;
}