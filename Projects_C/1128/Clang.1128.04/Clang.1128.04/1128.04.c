//�������j�b�g�@C����@���4�@�K��v�Z�̊֐�
//1423056�@�n糁@�ā@2014/11/28

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