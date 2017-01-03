//導入ユニット　C言語　問題5　関数Aから関数Bを呼び出す
//1423056　渡邉　翔　2014/12/5

#include <stdio.h>

float ave(int data[20]);
float var(int data[20]);

float ave(int data[20]){
	float num = 0;
	int i;
	for(i = 0;i<20;i++){
		num += data[i];
	}
	num/=20.0f;
	return num;
}

float var(int data[20]){
	float num = ave(data);
	float v = 0;
	int i;
	for(i = 0;i<20;i++){
		v +=((data[i]-num)*(data[i]-num));
	}
	v /= 20.0f;
	return v;
}

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
	int loop,tmax,tmin;
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
	float vr;
	printf("入力\n");
	inputData(data);
	printf("出力\n");
	outputData(data);

	minmax(data,&x,&n);
	printf("最大値：%d\n",x);
	printf("最小値：%d\n",n);

	vr = var(data);
	printf("分散：%f\n",vr);
    return 0;
}