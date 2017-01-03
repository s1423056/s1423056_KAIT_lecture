//導入ユニット　C言語　問題4　複雑な引数の利用
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

void minmax(int data[20], int *max, int *min){
	int loop,loop2,tmax,tmin;
	tmax = data[0];
	tmin = data[0];
	for(loop = 0; loop < 20; loop++){
		if(tmax < data[loop]) tmax = data[loop];
		if(tmin > data[loop]) tmin = data[loop];
	}
	*max = tmax;
	*min = tmin;
	return;
}

int main(){
	int data[20],x,n;
	printf("入力\n");
	inputData(data);
	printf("出力\n");
	outputData(data);

	minmax(data,&x,&n);
	printf("最大値：%d\n",x);
	printf("最小値：%d\n",n);

    return 0;
}