//導入ユニット　C言語　問題1
//1423056　渡邉　翔　2014/11/21

#include <stdio.h>

int main(){
	char ch = 'A';
	int loop;
	for(loop = 0;loop<26;loop++){
		printf("%c",ch+loop);
	}
	printf("\n");
    return 0;
}