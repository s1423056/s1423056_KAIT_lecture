//�������j�b�g�@C����@���2�@�z��������ɂ���
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

int main(){
	int data[20];
	printf("����\n");
	inputData(data);
	printf("�o��\n");
	outputData(data);
    return 0;
}