//
//

#include <stdio.h>
int stack[5] = {0,0,0,0,0},loop,count = 0;

void disp(){
		for(loop = 4;loop>=0;loop--){
		if(stack[loop]!=0){
			printf("[%d]",stack[loop]);
			count++;
		}
	}
	for(loop=0;loop<5-count;loop++){
		printf("[ ]");
	}
	count = 0;
	}

void push(int n){
	stack[4] = stack[3];
	stack[3] = stack[2];
	stack[2] = stack[1];
	stack[1] = stack[0];
	stack[0] = n;
	disp();
	printf("\n");
}

void pop(){
	printf("取り出し：%d\n",stack[0]);
	stack[0] = stack[1];
	stack[1] = stack[2];
	stack[2] = stack[3];
	stack[3] = stack[4];
	stack[4] = 0;
	disp();
	printf("\n");
}

int main(){
	printf("<スタックの出入り口を右とする>\n");
	push(1);
	push(2);
	push(3);
	pop();
	pop();
	push(4);
	pop();
	pop();

	return 0;
}