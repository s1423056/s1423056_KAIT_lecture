#include <stdio.h>
#include <string.h>

int main(){
	char input[81];
	int loop,num = 0;
	printf("整数を入力してください\n");
	scanf("%s",input);

	for(loop = 0;loop < strlen(input); loop++){
		if( ('0' <= input[loop]) && (input[loop] <= '9') ){
			num = 10*num+input[loop]-'0';
		}else{
			printf("整数入力になっていません\n");
			return 1;
		}
	}

	printf("数値：%d\n",num);
	return 0;
}