#include <stdio.h>

int count = 0;

//from:�ړ���
//work:��Ɨp
//dest:�ړ���
void move(int num, char *from, char *work, char *dest){
	if(num >= 1){
		move(num-1,from,dest,work);
		printf("%d��%s����%s�ֈړ�\n",num,from,dest);
		count++;
		move(num-1,work,from,dest);
	}
}

int main(){
	move(6,"A","B","C");
	printf("%d��ړ�\n",count);
	//2^n - 1��H
	return 0;
}

