//±üjbg@C¾ê@âè1@K(\¦EJèÔµEðªò)
//1423056@nç³@ãÄ@2014/10/24

#include <stdio.h>

int main(){
	int num,x,y;
	printf("3Èã40ÈºÌ®:");
	scanf("%d",&num);
	for(x = 0;x<num;++x){
		for(y=0;y<num;++y){
			if(x==0||y==0||x==(num-1)||y==(num-1))printf("*");
			else printf(" ");
		}
		printf("\n");
	}
    return 0;
}