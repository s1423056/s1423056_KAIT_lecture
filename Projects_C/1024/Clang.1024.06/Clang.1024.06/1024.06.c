//導入ユニット　C言語　問題6　スタック
//1423056　渡邉　翔　2014/10/24

#include <stdio.h>

int main(){
	int stack[5]={0,0,0,0,0},loop,count = 0;
	printf("<スタックの出入り口を右とする>\n");
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

	printf("取り出し：%d\n",stack[0]);

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

	printf("取り出し：%d",stack[0]);
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

	printf("取り出し：%d",stack[0]);
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

	printf("取り出し：%d",stack[0]);
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