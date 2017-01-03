#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOM 5

char field[5][5];

int count (int x, int y){
	int n = 0;
	if(x > 0 && y > 0 && field[x-1][y-1] & 0x01) n++;
	if(x > 0 && field[x-1][y] & 0x01) n++;
	if(x > 0 && y < 4 && field[x-1][y+1] & 0x01) n++;
	if(x > 0 && field[x][y-1] & 0x01) n++;
	if(x < 4 && field[x][y+1] & 0x01) n++;
	if(x < 4 && y > 0 && field[x+1][y-1] & 0x01) n++;
	if(x < 4 && field[x+1][y] & 0x01) n++;
	if(x < 4 && y < 4 && field[x+1][y+1] & 0x01) n++;
	return n;
}

int main(){
	int i,j,n,x,y,end = 0;
	int a = 0,b = 0;
	const char num[5][4] = {"0","1","2","3","4"};
	const char alp[5][4] = {"a ","b ","c ","d ","e"};
	char buf[81];

	srand((unsigned int)time(NULL));

	//�t�B�[���h�̏�����
	for(i = 0;i<5;i++){
		for(j = 0;j<5;j++){
			field[i][j] = 0x00;
		}
	}

	//�������g���Ĕ��e��z�u
	n = 0;
	while(n < BOM){
		x = rand() % 5;
		y = rand() % 5;
		if(!field[x][y] & 0x01){
			field[x][y] += 0x01;
			n++;
		}
	}

	while(!end){
		system("cls");//�R�}���h�v�����v�g�̉�ʂ��N���A
		printf("  ");
		for(i = 0; i < 5; i++) printf("%s",alp[i]);//��ʏ�̗��abcde��\��
		printf("\n");
		for(j = 0;j < 5;j++){
			printf("%s",num[j]);//��ʍ��ɐ�����\��
			for(i = 0;i < 5;i++){
				if(field[i][j] & 0x02){
					n = count(i,j);
					if(n) printf("%s",num[n]);
					else printf("  ");
				}
				else printf("��");
			}
			printf("\n");
		}

		// �N���A����
		n = 0;
		for(i = 0;i<5;i++){
			for(j = 0;j<5;j++){
				if(!field[i][j] & 0x02) n++;
			}
		}
		//���͂����߂�
		if(n != BOM){
			printf("\n������p�l�����w��\n");
			scanf("%s",buf);
			x = buf[0] - 'a';
			y = buf[1] - '0';
			if( x >= 0 && x < 5 && y >= 0 && y < 5  && !(field[x][y] & 0x02) ){
				if(field[x][y] & 0x01)end = 2;
				else field[x][y] += 0x02;
			}
			else end = 1;//�N���A
		}
	}

	// �I������
	system("cls");
	if(end == 1){
		//�N���A���̉�ʕ\��
		printf("  ");
		for(i = 0;i < 5;i++){
			printf("%s",alp[i]);
		}
		printf("\n");
		for(j = 0;j < 5;j++){
			printf("%s",num[j]);
			for(i = 0;i<5;i++){
				if(field[i][j] & 0x01) printf("��");
				else printf("  ");
			}
			printf("  ");
		}
		printf("\n�N���A�I\n");
	}else{
		//�Q�[���I�[�o�[���̉�ʕ\��
		printf("  ");
		for(i = 0;i<5;i++){
			printf("\n");
		}
		printf("\n");
		for(j = 0;j<5;j++){
			printf("%s",alp[i]);
		}
		printf("\n");
		for(j =0;j<5;j++){
			printf("%s",num[j]);
			for(i = 0;i<5;i++) printf("��");
			printf("\n");
		}
		printf("\n�Q�[���I�[�o�[\n");
	}
	return 0;
}