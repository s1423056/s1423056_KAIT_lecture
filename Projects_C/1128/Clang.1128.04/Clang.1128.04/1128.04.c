//導入ユニット　C言語　問題4　階乗計算の関数
//1423056　渡邉　翔　2014/11/28

#include <stdio.h>

int fanctorial(int n){
	int loop,N = n;
	for(loop = 1;loop<n;loop++) N *= (n - loop);
	return N;
}

int main(){
	int num = fanctorial(1);
	printf("%d\n",num);
    return 0;
}