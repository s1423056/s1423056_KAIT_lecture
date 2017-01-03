//導入ユニット　C言語　問題3　csvファイルの書き出し
//1423056　渡邉　翔　2014/10/31

#include <stdio.h>
#include <math.h>

int main(){
	FILE *fp;
	double a,b,loop;
	if((fp = fopen("output.csv","w")) == NULL){
		printf("ファイルが開けません\n");
		return 1;
	}

	for(loop = 1;loop<=200;loop++){
		a = 3.14*(loop/100);
		b = sin(a);
		fprintf(fp,"%lf,%lf\n",a,b);
		printf("%.0lf：",loop);
		printf("%.4lf,%.4lf\n",a,b);
	}
    return 0;
}