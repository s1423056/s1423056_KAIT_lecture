#include <stdio.h>

int main(){
	int val[11]={0};
	int num;
	int i;
	printf("������0~9��10����͂��Ă�������\n");
	for(i=0;i<10;i++){
		scanf("%d",&num);
		if(num < 0||num > 9)val[10]++;
		else val[num]++;
	}
	for(i=0;i<10;i++){
		printf("%d��%d����͂���܂���\n",i,val[i]);
	}
	printf("0�`9�ȊO�̐�����%d����͂���܂���\n",val[10]);
	return 0;
}