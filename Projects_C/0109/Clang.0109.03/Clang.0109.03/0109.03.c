//�������j�b�g�@C����@���R�@define�̎g�����𗝉�����
//1423056�@�n糁@�ā@2014/1/9

#include <stdio.h>

#define CLEN 81
#define SCORENUM 3
#define DATANUM 10

struct Dtype{
	char name[CLEN];
	char address[CLEN];
	int score[SCORENUM];
};

int printALL(struct Dtype data[], int Dnum){
	int loop,snum;
	for(loop = 0;loop < Dnum;loop++){
		printf("-----[%2d]-----\n",loop+1);
		printf("Name: %s\n",data[loop].name);
		printf("Address: %s\n",data[loop].address);
		for(snum = 0;snum<SCORENUM;snum++)
			printf("score[%d]:%3d\t",snum+1,data[loop].score[snum]);
		printf("\n");
	}
	return 0;
}

int inputData(struct Dtype data[], int *Dnum){
	int loop, addnum, snum;
	printf("���f�[�^��ǉ����܂����H[��%d�܂ŉ\]:", DATANUM-*Dnum);
	scanf("%d", &addnum);
	for(loop = *Dnum;loop<*Dnum+addnum;loop++){
		printf("Name:");scanf("%s",data[loop].name);
		printf("Address:");scanf("%s",data[loop].address);
		for(snum = 0; snum<SCORENUM;snum++){
			printf("score[%d]:",snum+1);scanf("%d",&data[loop].score[snum]);
		}
	}
	*Dnum=*Dnum+addnum;
	return 0;
}

int main(){
	struct Dtype data[DATANUM];
	int Dnum = 0;
	inputData(data,&Dnum);
	printALL(data,Dnum);
	printf("\n==Now Dnum=%d\n\n",Dnum);
	inputData(data, &Dnum);
	printALL(data,Dnum);
	return 0;
}
