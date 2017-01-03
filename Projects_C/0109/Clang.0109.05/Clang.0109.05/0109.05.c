//導入ユニット　C言語　問題5　構造体配列の関数受け渡し
//1423056　渡邉　翔　2014/1/9

#include <stdio.h>
#define DNUM 3

typedef struct Human_data{
	char name[81];
	char id[10];
}Human_data_type;

void inMod(Human_data_type d[]){
	int loop;
	for(loop = 0;loop < DNUM;loop++){
		printf("%3d:Name:", loop+1);
		scanf("%s",d[loop].name);
		printf("%3d:ID:", loop+1);
		scanf("%s",d[loop].id);
	}
}

void outMod(Human_data_type d[]){
	int loop;
	for(loop = 0;loop < DNUM;loop++){
		printf("%s\t", d[loop].name);
		printf("[%s]\n", d[loop].id);
	}
}

int main(){
	Human_data_type data[DNUM];
	inMod(data);
	outMod(data);
    return 0;
}