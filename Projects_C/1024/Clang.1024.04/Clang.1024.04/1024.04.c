//�������j�b�g�@C����@���4�@�z��̕��ёւ�
//1423056�@�n糁@�ā@2014/10/24

#include <stdio.h>

int main(){
	int num[5],loop,loop2;
	for(loop = 0; loop<5;++loop){
		printf("%d�ڂ̓��́F",loop+1);
		scanf("%d",&num[loop]);
	}
	for(loop = 0; loop<5;++loop){
		printf("%d�ڂ̐����F%d\n",loop+1,num[loop]);
	}

	for(loop=0;loop<4;++loop){
		for(loop2=loop+1;loop2<5;++loop2){
			if(num[loop]>num[loop2]){
				int t = num[loop];
				num[loop] = num[loop2];
				num[loop2] = t;
			}
		}
	}
	printf("�\�[�g��\n");
	for(loop = 0;loop<5;++loop){
		printf("%d\n",num[loop]);
	}
    return 0;
}