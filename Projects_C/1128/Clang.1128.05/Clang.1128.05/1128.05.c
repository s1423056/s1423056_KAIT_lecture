//�������j�b�g�@C����@���5�@�����L���`��ɂ��L�����N�^����
//1423056�@�n糁@�ā@2014/11/28

#include <stdio.h>

int draw1(){
	printf("( �v�E�ցE)�v���[\n");
	return 0;
}
int draw2(){
	printf("( /�E�ցE)/�ɂ�[\n");
	return 0;
}

int draw3(){
	printf("�G( > A<)�G�ʂ�[\n");
	return 0;
}

int draw4(){
	printf("��( �E�ցE)����ݼެ�� \n");
	return 0;
}

int main(){
	int num;
	do{
		scanf("%d",&num);
		switch(num){
			case 0: printf("�I�����܂��B\n");break;
			case 1: draw1();break;
			case 2: draw2();break;
			case 3: draw3();break;
			case 4: draw4();break;
			default: printf("1~4�ȊO�̐��������͂���܂���\n");
		}
	}while(num != 0);
    return 0;
}