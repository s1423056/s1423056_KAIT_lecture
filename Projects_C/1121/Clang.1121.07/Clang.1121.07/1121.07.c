//導入ユニット　C言語　問題7　strcmp()の利用
//1423056　渡邉　翔　2014/11/21

#include <stdio.h>
#include <string.h>

int main(){
	FILE *fp;
	char str[16],input[80];
	int hindo = 0;
	if( (fp = fopen("input3.txt","r")) == NULL ) {
		printf("File Open Error!\n");
		return 1;
	}
	printf("検索したい文字列：");
	scanf("%s",str);
	while(fscanf(fp,"%s",input) != EOF){
		if(strcmp(str,input) == 0){
			hindo += 1;
		}
	}
	printf("同じ文字列の数：%d\n",hindo);
    return 0;
}