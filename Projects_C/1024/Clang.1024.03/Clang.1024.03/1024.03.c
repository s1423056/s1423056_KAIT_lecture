//導入ユニット　C言語　問題3　配列の値から計算した値を別配列の中に入れる
//1423056　渡邉　翔　2014/10/24

#include <stdio.h>

int main(){
	int A[10],loop;
	float B[10],ave = 0;

	for(loop=0; loop<10;++loop){
		printf("%d個目の整数入力：",loop+1);
		scanf("%d",&A[loop]);
		ave+=A[loop];
	}
	ave = ave /10.0;
	printf("平均：%.1f\n",ave);

	for(loop = 0;loop<10;++loop){
		B[loop] = (A[loop] - ave);
		printf("要素%d：%d,%.1f\n",loop+1,A[loop],B[loop]);
	}

    return 0;
}