//�������j�b�g�@C����@���4�@��d�J��Ԃ������𗘗p�������̕\�쐬
//1423056�@�n糁@�ā@2014/10/10

#include <stdio.h>

int main(){
	int x,y;
	printf("10x19\n");

	for(y = 10; y <= 19; y++){
		for(x = 10; x <= 19; x++){
			printf("%4d",x*y);
		}
		printf("\n");
	}
	return 0;
}