//�������j�b�g�@C����@���6�@���ȗ\��V�X�e��
//1423056�@�n糁@�ā@2014/11/28

#include <stdio.h>
#include <string.h>

// �v���g�^�C�v�֐�
int regist();					// �\��
int counter();				// �\�񐔂��m�F
int registmax();			// �\��ő吔���m�F
int changemax();		// �\��ő吔��ύX
int clear();					// �\���S����

// ���C���֐�
int main()
{
	int num,num2;

	if( counter() >= registmax())
	{
		printf("�\�񐔂��ő�ł�\n");
		return 1;
	}
	printf("���l����͂��ē����I�����Ă��������B\n1�F�\��@2�F�\�񐔊m�F�@3�F�ő�\�񐔕ύX�@0�F�\���S����\n");
	scanf("%d",&num);
	switch(num)
	{
		case 0:
			clear();
			break;
		case 1:
			regist();
			break;
		case 2:
			printf("���݂̗\�񐔂�%d���ł�\n",counter());
			break;
		case 3:
			changemax();
			break;
		default:
			printf("�s���ȓ��͂ł��B\n");
	}
	
    return 0;
}

// �\�񐔂��m�F
int counter()
{
	FILE *fp;
	int i = 0,count = 0;
	char name[100];

	fp = fopen("zaseki.txt","r");
	while(fgets(name, 100, fp) != NULL)
	{
		if(i > 0)count++;
		i++;
	}
	fclose(fp);
	return count;
}

// �\��
int regist()
{
	FILE *fp;
	char name[100];

	if((fp = fopen("zaseki.txt","a")) == NULL)
	{
		printf("File Open Error\n");
		return 1;
	}
	printf("���Ȃ�\�񂵂܂��B\n���O�F");
	gets_s(name,sizeof(name) - 1);
	gets_s(name,sizeof(name) - 1);
	if(name[0] != NULL)
	{
		fprintf(fp,"%s\n",name);
		printf("�\�񂵂܂����B\n");
	}
	else
		printf("���O�̓��͂Ɏ��s���܂����B\n");
	fclose(fp);
	return 0;
}

// �\��ő吔���m�F
int registmax()
{
	FILE *fp;
	char cnum[8];
	int inum = 0,loop;

	if((fp = fopen("max.txt","r")) == NULL)
	{
		printf("File Open Error\n");
		return 1;
	}
	fgets(cnum,sizeof(cnum),fp);
	for(loop = 0;loop < strlen(cnum);loop++)
	{
		if('0'<=cnum[loop] && cnum[loop] <= '9') 
		inum = inum*10+cnum[loop]-'0';
	}
	fclose(fp);
	return inum;
}

// �\��ő吔��ύX
int changemax()
{
	FILE *fp;
	char num[8];
	int n,loop;

	printf("���Ȃ̍ő吔����͂��Ă��������F");
	scanf("%d",&n);
	if((fp = fopen("max.txt","w")) == NULL)
	{
		printf("File Open Error\n");
		return 1;
	}
	sprintf(num,"%d",n);
	fputs(num,fp);
	fclose(fp);
	printf("���Ȃ̍ő吔��%d�ȂɕύX���܂����B\n",registmax());
	return 0;
}

// �\���S����
int clear(){
	FILE *fp;
	int num;

	printf("�\���S�������܂��B��낵���ł����H\n");
	printf("���l����͂��đI�����Ă��������B\n1�F�͂��@0�F������\n");
	scanf("%d",&num);
	if(num == 1)
	{
		if((fp = fopen("zaseki.txt","w")) == NULL)
		{
			printf("File Open Error\n");
			return 1;
		}
		fprintf(fp,"");
		fclose(fp);
		printf("�\���S�������܂����B\n");
	}
	else
		printf("�\��̑S�������L�����Z�����܂����B\n");
	return 0;
}