//導入ユニット　C言語　問題5　strcmp()の利用
//1423056　渡邉　翔　2014/11/21

#include <stdio.h>
#include <string.h>

int main(){
	char str[80];
	do{
		printf("「Yes」と入力してください：");
		scanf("%s",str);
	}while(strcmp(str,"Yes") != 0);
    return 0;
}