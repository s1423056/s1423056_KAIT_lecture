//導入ユニット　C言語　問題2　配列に値を格納する
//1423056　渡邉　翔　2014/10/24

#include <stdio.h>

int main(){
	float num[10],ave=0.0;
	int loop;
	for(loop = 0;loop<10;++loop){
		printf("%d人目の身長：",loop+1);
		scanf("%f",&num[loop]);
		ave += num[loop];
	}
	ave  = ave / 10;
	printf("10人の平均身長：%.1f\n",ave);

	for(loop = 0;loop<10;++loop){
		printf("%d人目の身長：%f\n",loop+1,num[loop]);
	}

    return 0;
}