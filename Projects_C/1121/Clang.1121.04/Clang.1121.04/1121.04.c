//導入ユニット　C言語　問題4　ファイル入出力
//1423056　渡邉　翔　2014/11/21

#include <stdio.h>

int main(){
	FILE *fp1,*fp2;
	char moji[80];
	int loop;

	fp1 = fopen("input.txt","r");
	fp2 = fopen("output.txt","w");

	fscanf(fp1,"%s",moji);
	for(loop = 0; loop < 80;loop++){
		if('a'<=moji[loop] && moji[loop] <= 'z'){
			moji[loop]-=('a'-'A');
		}else if('A'<=moji[loop] && moji[loop] <= 'Z'){
			moji[loop]+=('a'-'A');
		}
	}
	printf("%s\n",moji);
	fprintf(fp2,"%s",moji);
	fclose(fp2);
	fclose(fp1);
    return 0;
}