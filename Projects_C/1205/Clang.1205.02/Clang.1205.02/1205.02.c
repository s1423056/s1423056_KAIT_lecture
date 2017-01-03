//導入ユニット　C言語　問題2　配列を引数にする
//1423056　渡邉　翔　2014/12/5

#include <stdio.h>
void inputData(int data[20]){
	int i,num;
	for(i = 0; i <20;i++){
		printf("%d人目の点数:",i+1);
		scanf("%d",&num);
		data[i] = num;
	}
	return;
}

void outputData(int data[20]){
	int i;
	for(i = 0;i<20;i++){
		printf("%d人目の点数:%d\n",i+1,data[i]);
	}
}

int main(){
	int data[20];
	printf("入力\n");
	inputData(data);
	printf("出力\n");
	outputData(data);
    return 0;
}