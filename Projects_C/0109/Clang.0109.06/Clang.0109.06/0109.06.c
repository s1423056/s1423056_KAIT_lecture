//�������j�b�g�@C����@���U�@�������̂��߂Ƀv���O�������l����P
//1423056�@�n糁@�ā@2014/1/9

#include <stdio.h>

int main(){
	// �d���ꉿ�i�A�d������A�ڕW���v�i�����v�j
	int codeprice,codenum,targetprofit;
	// �̔����A�̔��z�A�݌ɐ��A���v����グ
	int num = 0,price = 0,totalstock = 0,totalsales = 0;

	printf("�d���ꉿ�i�F"); scanf("%d",&codeprice);
	printf("�d������F"); scanf("%d",&codenum);
	printf("�ڕW���v�F"); scanf("%d",&targetprofit);
	printf("========================================\n");
	totalstock = codenum;

	do{
	printf("���̍݌ɐ��F%d\n",totalstock);
	printf("�Ԏ��ɂȂ�Ȃ��Œቿ�i�F%d\n", (codeprice - totalsales) / totalstock);
	printf("�ڕW���v�B���ɕK�v�ȍŒቿ�i�F%d\n", ( (codeprice + targetprofit) - totalsales ) / totalstock );
	printf("----------------------------------------\n");

	do{
	printf("�̔����F"); scanf("%d",&num);
	if(num > totalstock)printf("���͂��ꂽ�����s���ł��B\n");
	}while(num > totalstock);

	printf("�̔����i�F"); scanf("%d",&price);
	printf("========================================\n");
	printf("\n");
	printf("========================================\n");
	totalsales += (price*num);
	totalstock -= num;
	}while(totalstock > 0);

	printf("�����v�F%d\n",totalsales - codeprice);
	printf("========================================\n");
	return 0;
}