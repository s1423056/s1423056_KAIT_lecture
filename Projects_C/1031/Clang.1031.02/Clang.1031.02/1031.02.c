//�������j�b�g�@C����@���2�@�t�@�C���ւ̏o��
//1423056�@�n糁@�ā@2014/10/31

#include <stdio.h>

int main(){
	FILE *fp;
	int num,month,day,all;
	if((fp = fopen("log1.txt","r")) == NULL){
		printf("�t�@�C�����J���܂���B\n");
		return 1;
	}
	if((fp = fopen("log1.txt","w")) == NULL){
		printf("�t�@�C�����J���܂���B\n");
		return 1;
	}
	printf("�w�Дԍ��F");
	scanf("%d",&num);
	printf("�a�����F");
	scanf("%d",&month);
	printf("�a�����F");
	scanf("%d",&day);
	all = month*100+day;
	fprintf(fp,"%d\n",num);
	fprintf(fp,"%d\n",all);
	printf("�w�Дԍ�%d\n",num);
	printf("�a������%d\n",all);
	fclose(fp);
    return 0;
}