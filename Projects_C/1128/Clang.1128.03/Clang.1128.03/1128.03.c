//�������j�b�g�@C����@���3�@�ׂ���v�Z�̊֐�
//1423056�@�n糁@�ā@2014/11/28

#include <stdio.h>

int power(int n, int k){
	int i,N = n;
	for(i = 1;i<k;i++) N *= n;
	return N;
}

int main(){
	int num = power(2,3);
	printf("%d\n",num);
    return 0;
}