//�������j�b�g�@C����@���4�@�t�@�C�����琔�l�̓ǂݎ��
//1423056�@�n糁@�ā@2014/10/31

#include <stdio.h>

int main(){
	FILE *fp;
	int num = 0,month = 0,day = 0,all = 0;
	if((fp = fopen("log1.txt","r")) == NULL){
		printf("�t�@�C�����J���܂���B\n");
		return 1;
	}

	fscanf(fp,"%d",&num);
	printf("�w�Дԍ��F%d\n",num);

	fscanf(fp,"%d",&all);
	month = all /100;
	day = all-(month*100);
	printf("�a�����F%d���@%d��\n",month,day);
	fclose(fp);
    return 0;
}