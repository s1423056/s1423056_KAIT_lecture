//�������j�b�g�@C����@���6�@�������K
//1423056�@�n糁@�ā@2014/12/19

#include <stdio.h>

typedef struct ITEM{
	int itemID;
	int num;
}Item;

//�f�[�^������
void initialize(Item *i[]){
	i[0]->itemID = 4;
	i[0]->num = 3;
	i[1]->itemID = 1;
	i[1]->num = 5;
	i[2]->itemID = 2;
	i[2]->num = 10;
	i[3]->itemID = 5;
	i[3]->num = 2;
	i[4]->itemID = 3;
	i[4]->num = 6;
}

//�f�[�^�\��
void itemlist(Item *i[]){
	int loop;
	for(loop = 0; loop < 5; loop++)
		printf("ID:%d�A%d��\n",i[loop]->itemID,i[loop]->num);
}

//�f�[�^�\�[�g
int sort(Item *i[]){
	int n,loop,loop2;
	Item *tmp;	
	printf("1:�ԍ����A2:�����������A0:�I��\n");
	scanf("%d",&n);
	switch(n){
	case 1:
		for(loop = 0;loop < 4;loop++){
			for(loop2 = loop;loop2 < 5;loop2++){
				if(i[loop]->itemID > i[loop2]->itemID){
					tmp = i[loop];
					i[loop] = i[loop2];
					i[loop2] = tmp;
				}
			}
		}
		itemlist(i);
		break;
	case 2:
		for(loop = 0;loop < 4;loop++){
			for(loop2 = loop;loop2 < 5;loop2++){
				if(i[loop]->num < i[loop2]->num){
					tmp = i[loop];
					i[loop] = i[loop2];
					i[loop2] = tmp;
				}
			}
		}
		itemlist(i);
		break;
	case 0:
		printf("�I�����܂��B\n");
		break;
	default:
		printf("�s���ȓ��͂ł��B\n");
	}
	return n;
}

//���C���֐�
int main(){
	Item item[5];
	Item *ptr[5];
	int loop,num;
	for(loop = 0;loop < 5;loop++)
		ptr[loop] = &item[loop];
	initialize(ptr);
	itemlist(ptr);
	do{
		printf("�\�[�g���܂��B��������͂��Ă��������B\n");
		num = sort(ptr);//sort�֐�����0�����͂��ꂽ�ꍇwhile���[�v�I��
	}while(num != 0);
    return 0;
}