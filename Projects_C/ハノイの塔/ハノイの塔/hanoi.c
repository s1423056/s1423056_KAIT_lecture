#include <stdio.h>

int count = 0;

//from:移動元
//work:作業用
//dest:移動先
void move(int num, char *from, char *work, char *dest){
	if(num >= 1){
		move(num-1,from,dest,work);
		printf("%dを%sから%sへ移動\n",num,from,dest);
		count++;
		move(num-1,work,from,dest);
	}
}

int main(){
	move(6,"A","B","C");
	printf("%d回移動\n",count);
	//2^n - 1回？
	return 0;
}

