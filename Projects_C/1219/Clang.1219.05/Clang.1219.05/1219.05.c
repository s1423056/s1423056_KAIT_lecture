//導入ユニット　C言語　問題
//1423056　渡邉　翔　2014/12/19

#include <stdio.h>

int main(){
	int aa = 0, bb = 1, cc = 2;
	int dd[5] = {10,20,30,40,50};
	double ee[3] = {0.1, 0.02, 0.003};
	int *pt;
	int loop;

	printf("\n--Point A--\n");
	printf("[%d][%d]\n",aa,&aa);
	printf("[%d][%d]\n",bb,&bb);
	printf("[%d][%d]\n",cc,&cc);

	printf("\n--Point B--\n");
	for(loop = 0;loop<5;loop++){
		printf("[%d][%d]\n",dd[loop],&dd[loop]);
	}

	printf("\n--Point C--\n");
	for(loop = 0;loop<3;loop++){
		printf("[%f][%d]\n",ee[loop],&ee[loop]);
	}
	
	printf("\n--Point D--\n");
	printf("[%d][%d]\n",dd[0],&dd[0]);
	printf("[%d][%d]\n",dd[1],&dd[1]);
	pt = &dd[0];
	*pt = *pt+100;
	pt++;
	*pt = *pt+1000;

	printf("\n--Point E--\n");
	printf("[%4d][%d]\n",dd[0],&dd[0]);
	printf("[%4d][%d]\n",dd[1],&dd[1]);

	return 0;
}