//�������j�b�g�@C����@���R�@�\���̂��g���ăv���O�������\�z����
//1423056�@�n糁@�ā@2014/1/16

#include <stdio.h>

typedef struct data{
	char name[32];
	int koku,suu,ei,ri,sya;
}DATA;

int main(){
	int loop;
	DATA data[20];
	FILE *fp;
 
	if((fp = fopen("data.txt","w")) == NULL){
		printf("�t�@�C���̍쐬�Ɏ��s���܂���\n");
		return 1;
	}
	for(loop = 0;loop<20;loop++){
		printf("%2d\n",loop+1);
		printf("���O�F");scanf("%s",data[loop].name);
		printf("����F");scanf("%d",&data[loop].koku);
		printf("���w�F");scanf("%d",&data[loop].suu);
		printf("�p��F");scanf("%d",&data[loop].ei);
		printf("���ȁF");scanf("%d",&data[loop].ri);
		printf("�Љ�F");scanf("%d",&data[loop].sya);
		printf("============================\n");
		fprintf(fp,"���O�F%s\n",data[loop].name);
		fprintf(fp,"����F%d\n",data[loop].koku);
		fprintf(fp,"���w�F%d\n",data[loop].suu);
		fprintf(fp,"�p��F%d\n",data[loop].ei);
		fprintf(fp,"���ȁF%d\n",data[loop].ri);
		fprintf(fp,"�Љ�F%d\n",data[loop].sya);
		fprintf(fp,"============================\n");
	}
	fclose(fp);
    return 0;
}