//�������j�b�g�@C����@���6�@�f������
//1423056�@�n糁@�ā@2014/10/17

#include <stdio.h>

int main(){
	int num,check=0,loop;
	printf("���R������́F");
	scanf("%d",&num);

	while(num < 1){
		printf("�l���s���ł�\n");
		printf("���R������́F");
		scanf("%d",&num);
	}
	for(loop = 2;loop<num/2+1;loop++){
		if(num%loop == 0) check = 1;
	}
	if(check == 1) printf("�f���ł͂���܂���\n");
	else printf("�f���ł�\n");
    return 0;
}