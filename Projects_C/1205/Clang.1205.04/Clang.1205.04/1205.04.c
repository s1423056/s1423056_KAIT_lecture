//�������j�b�g�@C����@���4�@���G�Ȉ����̗��p
//1423056�@�n糁@�ā@2014/12/5

#include <stdio.h>

void inputData(int data[20]){
	int i,num;
	for(i = 0; i <20;i++){
		printf("%d�l�ڂ̓_��:",i+1);
		scanf("%d",&num);
		data[i] = num;
	}
	return;
}

void outputData(int data[20]){
	int i;
	for(i = 0;i<20;i++){
		printf("%d�l�ڂ̓_��:%d\n",i+1,data[i]);
	}
}

void minmax(int data[20], int *max, int *min){
	int loop,loop2,tmax,tmin;
	tmax = data[0];
	tmin = data[0];
	for(loop = 0; loop < 20; loop++){
		if(tmax < data[loop]) tmax = data[loop];
		if(tmin > data[loop]) tmin = data[loop];
	}
	*max = tmax;
	*min = tmin;
	return;
}

int main(){
	int data[20],x,n;
	printf("����\n");
	inputData(data);
	printf("�o��\n");
	outputData(data);

	minmax(data,&x,&n);
	printf("�ő�l�F%d\n",x);
	printf("�ŏ��l�F%d\n",n);

    return 0;
}