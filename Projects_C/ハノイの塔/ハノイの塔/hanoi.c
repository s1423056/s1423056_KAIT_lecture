#include <stdio.h>

int count = 0;

//from:ˆÚ“®Œ³
//work:ì‹Æ—p
//dest:ˆÚ“®æ
void move(int num, char *from, char *work, char *dest){
	if(num >= 1){
		move(num-1,from,dest,work);
		printf("%d‚ğ%s‚©‚ç%s‚ÖˆÚ“®\n",num,from,dest);
		count++;
		move(num-1,work,from,dest);
	}
}

int main(){
	move(6,"A","B","C");
	printf("%d‰ñˆÚ“®\n",count);
	//2^n - 1‰ñH
	return 0;
}

