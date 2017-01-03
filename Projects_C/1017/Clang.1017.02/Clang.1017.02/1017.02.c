//導入ユニット　C言語　問題2　最大・最小値を求める
//1423056　渡邉　翔　2014/10/17

#include <stdio.h>

int main(){
	int num,i,max,min;
	float all = 0;
	for(i = 1;i<=10;i++){
		printf("%d回目整数を入力：",i);
		scanf("%d",&num);
		if(i == 1){
			max = num;
			min = num;
		}
		all=all+num;
		if(max < num)max = num;
		if(min > num)min = num;
	}
	all=all/10.0;
	printf("平均は：%f\n",all);
	printf("最大値は：%d\n",max);
	printf("最小値は：%d\n",min);

    return 0;
}