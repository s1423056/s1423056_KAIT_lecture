#include <stdio.h>

int main(){
	int val[11]={0};
	int num;
	int i;
	printf("”š‚Ì0~9‚ğ10‰ñ“ü—Í‚µ‚Ä‚­‚¾‚³‚¢\n");
	for(i=0;i<10;i++){
		scanf("%d",&num);
		if(num < 0||num > 9)val[10]++;
		else val[num]++;
	}
	for(i=0;i<10;i++){
		printf("%d‚ª%d‰ñ“ü—Í‚³‚ê‚Ü‚µ‚½\n",i,val[i]);
	}
	printf("0`9ˆÈŠO‚Ì”š‚ª%d‰ñ“ü—Í‚³‚ê‚Ü‚µ‚½\n",val[10]);
	return 0;
}