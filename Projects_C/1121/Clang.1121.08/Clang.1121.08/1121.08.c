//導入ユニット　C言語　問題8　文字と文字列の置換
//1423056　渡邉　翔　2014/11/21
#include <stdio.h>
#include <string.h>

int main(){
	char moji[80],moji2[2],moji3[160];
	int loop,loop2;

	printf("対象文字列：");
	scanf("%s",moji);
	printf("置換元文字：");
	scanf("%s",moji2);
	printf("置換文字列：");
	scanf("%s",moji3);

	for(loop = 0;loop < strlen(moji);loop++){
		if(moji[loop] == moji2[0]){
			for(loop2 = strlen(moji); loop2 > loop; loop2--){
				moji[loop2+strlen(moji3)-1] = moji[loop2];
			}
			for(loop2 = loop;loop2<loop+strlen(moji3);loop2++){
				moji[loop2] = moji3[loop2-loop];
			}
		}
	}
	printf("結果文字列：%s\n",moji);
	return 0;
}