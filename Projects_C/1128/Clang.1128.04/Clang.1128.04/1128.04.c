//±üjbg@C¾ê@âè4@KævZÌÖ
//1423056@nç³@ãÄ@2014/11/28

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