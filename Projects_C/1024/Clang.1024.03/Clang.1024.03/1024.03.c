//�������j�b�g�@C����@���3�@�z��̒l����v�Z�����l��ʔz��̒��ɓ����
//1423056�@�n糁@�ā@2014/10/24

#include <stdio.h>

int main(){
	int A[10],loop;
	float B[10],ave = 0;

	for(loop=0; loop<10;++loop){
		printf("%d�ڂ̐������́F",loop+1);
		scanf("%d",&A[loop]);
		ave+=A[loop];
	}
	ave = ave /10.0;
	printf("���ρF%.1f\n",ave);

	for(loop = 0;loop<10;++loop){
		B[loop] = (A[loop] - ave);
		printf("�v�f%d�F%d,%.1f\n",loop+1,A[loop],B[loop]);
	}

    return 0;
}