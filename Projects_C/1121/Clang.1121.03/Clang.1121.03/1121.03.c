//導入ユニット　C言語　問題3　大文字小文字変換
//1423056　渡邉　翔　2014/11/21

#include <stdio.h>

int main(){
	char moji[80];
	int loop;
	scanf("%s",moji);
	for(loop = 0; loop < 80;loop++){
		if('a'<=moji[loop] && moji[loop] <= 'z'){
			moji[loop]-=32;
		}else if('A'<=moji[loop] && moji[loop] <= 'Z'){
			moji[loop]+=32;
		}
	}
	printf("%s\n",moji);

    return 0;
}