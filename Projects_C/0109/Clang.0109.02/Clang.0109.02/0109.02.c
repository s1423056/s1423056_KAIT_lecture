//“±“üƒ†ƒjƒbƒg@CŒ¾Œê@–â‘è‚Q@—ñ‹“Œ^‚ÉG‚ê‚é
//1423056@“nç³@ãÄ@2014/1/9

#include <stdio.h>

enum WeekT{Sun, Mon, Tue, Wed, Thu, Fri, Sat};

int main(){
	enum WeekT input;
	printf("¡“ú‚Ì—j“ú‚ğ”Ô†‚Å“ü‚ê‚Ä‚­‚¾‚³‚¢\n");
	printf("0:Sun\n1:Mon\n2:Tue\n3:Wed\n4:Thu\n5:Fri\n6:Sat\n");
	scanf("%d",&input);
	switch(input){
		case Sun:printf("“ú—j“ú‚Å‚·\n");break;
		case Mon:printf("Œ—j“ú‚Å‚·\n");break;
		case Tue:printf("‰Î—j“ú‚Å‚·\n");break;
		case Wed:printf("…—j“ú‚Å‚·\n");break;
		case Thu:printf("–Ø—j“ú‚Å‚·\n");break;
		case Fri:printf("‹à—j“ú‚Å‚·\n");break;
		case Sat:printf("“y—j“ú‚Å‚·\n");break;
		default:printf("“ü—Í‚ª•s³‚Å‚·");
	}
	printf("----------\n");
	printf("Sum:%d\n",Sun);
	printf("Mon:%d\n",Mon);
	printf("Tue:%d\n",Tue);
    return 0;
}