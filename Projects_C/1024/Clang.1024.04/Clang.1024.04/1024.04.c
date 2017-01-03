//導入ユニット　C言語　問題4　配列の並び替え
//1423056　渡邉　翔　2014/10/24

#include <stdio.h>

int main(){
	int num[5],loop,loop2;
	for(loop = 0; loop<5;++loop){
		printf("%d個目の入力：",loop+1);
		scanf("%d",&num[loop]);
	}
	for(loop = 0; loop<5;++loop){
		printf("%d個目の整数：%d\n",loop+1,num[loop]);
	}

	for(loop=0;loop<4;++loop){
		for(loop2=loop+1;loop2<5;++loop2){
			if(num[loop]>num[loop2]){
				int t = num[loop];
				num[loop] = num[loop2];
				num[loop2] = t;
			}
		}
	}
	printf("ソート後\n");
	for(loop = 0;loop<5;++loop){
		printf("%d\n",num[loop]);
	}
    return 0;
}