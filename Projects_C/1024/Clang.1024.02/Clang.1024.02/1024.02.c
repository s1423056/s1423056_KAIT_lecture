//�������j�b�g�@C����@���2�@�z��ɒl���i�[����
//1423056�@�n糁@�ā@2014/10/24

#include <stdio.h>

int main(){
	float num[10],ave=0.0;
	int loop;
	for(loop = 0;loop<10;++loop){
		printf("%d�l�ڂ̐g���F",loop+1);
		scanf("%f",&num[loop]);
		ave += num[loop];
	}
	ave  = ave / 10;
	printf("10�l�̕��ϐg���F%.1f\n",ave);

	for(loop = 0;loop<10;++loop){
		printf("%d�l�ڂ̐g���F%f\n",loop+1,num[loop]);
	}

    return 0;
}