//導入ユニット　C言語　問題5　ファイルにある数字をすべて読み込む
//1423056　渡邉　翔　2014/10/31

#include <stdio.h>

int main(){
	FILE *fp;
	double num = 0,sum = 0,ave = 0,var = 0,pro = 0;
	int count = 0;

	if((fp = fopen("input.txt","r")) == NULL){
		printf("ファイルを開けません。\n");
		return 1;
	}
	while((fscanf(fp,"%lf",&num) != EOF)){
		sum += num;
		pro += (num*num);
		
		count++;
		printf("%lf\n",num);
	}
	ave = sum / count;
	rewind(fp);

	while((fscanf(fp,"%lf",&num) != EOF)){
		var += (num-ave)*(num-ave);
	}
	var /= count;

	printf("合計：%lf\n",sum);
	printf("数値の個数：%d\n",count);
	printf("平均値：%lf\n",ave);
	printf("分散：%lf\n",var);

	fclose(fp);

    return 0;
}