//�������j�b�g�@C����@���6�@�X�^�b�N
//1423056�@�n糁@�ā@2014/10/24

#include <stdio.h>

int main(){
	int stack[5]={0,0,0,0,0},loop,count = 0;
	printf("<�X�^�b�N�̏o��������E�Ƃ���>\n");
	stack[0] = 1;
	
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
	printf("\n");

	stack[1] = stack[0];
	stack[0] = 2;
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
	printf("\n");

	stack[2] = stack[1];
	stack[1] = stack[0];
	stack[0] = 3;
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
	printf("\n");

	printf("���o���F%d\n",stack[0]);

	stack[0] = stack[1];
	stack[1] = stack[2];
	stack[2] = 0;
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
	printf("\n");

	printf("���o���F%d",stack[0]);
	printf("\n");

	stack[0] = stack[1];
	stack[1] = 0;

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
	printf("\n");
	

	stack[3] = stack[2];
	stack[2] = stack[1];
	stack[1] = stack[0];
	stack[0] = 4;
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
	printf("\n");

	printf("���o���F%d",stack[0]);
	printf("\n");

	stack[0] = stack[1];
	stack[1] = 0;

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
	printf("\n");

	printf("���o���F%d",stack[0]);
	printf("\n");

	stack[0] = 0;

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
	printf("\n");

	

    return 0;
}