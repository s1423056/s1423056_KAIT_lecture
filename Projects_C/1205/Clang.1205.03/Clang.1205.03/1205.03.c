//導入ユニット　C言語　問題3　再帰的な関数の呼び出し
//1423056　渡邉　翔　2014/12/5

#include <stdio.h>
void recursiveCall(int num);
void recursiveCall(int num){
	if(num > 0){
		//A
		printf("A\n");
		printf("%d\n",num);
		//B
		printf("B\n");
		recursiveCall(num-1);
		//C
		printf("C\n");
	}
	
	//D
	printf("D\n");
	return;
}

int main(){
	int num = 5;
	printf("Inputnum = 5\n");
	//E
	printf("E\n");
	recursiveCall(num);
	//F
	printf("F\n");
    return 0;
}