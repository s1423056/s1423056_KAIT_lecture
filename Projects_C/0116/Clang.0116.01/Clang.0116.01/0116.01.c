//�������j�b�g�@C����@���P�@���������I�m�ۂɐG���
//1423056�@�n糁@�ā@2014/1/16

#include <stdio.h>
#include <stdlib.h>

int main(){
	int n,i;
	int * data;
	printf("���f�[�^�����܂����H�F"); scanf("%d",&n);
	data = malloc(sizeof(int)*n);
	if(data == NULL){
		fprintf(stderr,"�������s��\n");
	}
	printf("OK\n");
	for(i = 0;i<n;i++){
		printf("%d:",i); scanf("%d",&data[i]);
	}
	for(i = 0;i<n;i++)
		printf("%d\n",data[i]);
    return 0;
}