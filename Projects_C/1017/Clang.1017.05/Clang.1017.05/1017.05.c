//導入ユニット　C言語　問題5　等差数列の和
//1423056　渡邉　翔　2014/10/17

#include <stdio.h>

int main(){
	float begin,end,dif = 0,total = 0;
	int num,i;
	printf("初項：");
	scanf("%f",&begin);
	printf("末項：");
	scanf("%f",&end);
	printf("項数：");
	scanf("%d",&num);

	printf("公式を利用して求める場合：%f\n",num*(begin+end)/2);

	dif = (end - begin)/(num - 1);

	for(i = 0;i<num;i++){
		total += (begin+dif*i);
	}
	printf("1つずつの項を順次足し合わせる場合：%f\n",total);
    return 0;
}