//導入ユニット　C言語　問題3　ファイルから数値の読み取り
//1423056　渡邉　翔　2014/10/31

#include <stdio.h>

int main(){
	FILE *fp;
	int num[20],loop,ave = 0,max = 0,min = 0;
	fp = fopen("input.txt","w");
	fprintf(fp,"1\n2\n3\n4\n5\n6\n7\n8\n9\n10\n11\n12\n13\n14\n15\n16\n17\n18\n19\n20\n");
	fclose(fp);
	fp = fopen("input.txt","r");
	for(loop = 0;loop<20;loop++){
		
		fscanf(fp,"%d",&num[loop]);
		printf("%d番目の数値：%d\n",loop+1,num[loop]);
		ave += num[loop];
		if(max < num[loop]) max = num[loop];
		if(min > num[loop]) min = num[loop];
		if(loop == 0){
			min = max = num[0];
		}else{
			if(max < num[loop]) max = num[loop];
			if(min > num[loop]) min = num[loop];
		}
	}
	ave /= 20;
	
	printf("最大値：%d\n",max);
	printf("最小値：%d\n",min);
	printf("平均値：%d\n",ave);
    return 0;
}