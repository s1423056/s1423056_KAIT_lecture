//導入ユニット　C言語　問題２　列挙型に触れる
//1423056　渡邉　翔　2014/1/9

#include <stdio.h>

enum WeekT{Sun, Mon, Tue, Wed, Thu, Fri, Sat};

int main(){
	enum WeekT input;
	printf("今日の曜日を番号で入れてください\n");
	printf("0:Sun\n1:Mon\n2:Tue\n3:Wed\n4:Thu\n5:Fri\n6:Sat\n");
	scanf("%d",&input);
	switch(input){
		case Sun:printf("日曜日です\n");break;
		case Mon:printf("月曜日です\n");break;
		case Tue:printf("火曜日です\n");break;
		case Wed:printf("水曜日です\n");break;
		case Thu:printf("木曜日です\n");break;
		case Fri:printf("金曜日です\n");break;
		case Sat:printf("土曜日です\n");break;
		default:printf("入力が不正です");
	}
	printf("----------\n");
	printf("Sum:%d\n",Sun);
	printf("Mon:%d\n",Mon);
	printf("Tue:%d\n",Tue);
    return 0;
}