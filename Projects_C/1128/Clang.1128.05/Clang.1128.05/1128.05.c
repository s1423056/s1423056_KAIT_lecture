//導入ユニット　C言語　問題5　文字記号描画によるキャラクタ操作
//1423056　渡邉　翔　2014/11/28

#include <stdio.h>

int draw1(){
	printf("( 」・ω・)」うー\n");
	return 0;
}
int draw2(){
	printf("( /・ω・)/にゃー\n");
	return 0;
}

int draw3(){
	printf("；( > A<)；ぬわー\n");
	return 0;
}

int draw4(){
	printf("∩( ・ω・)∩ﾊﾞﾝｼﾞｬｰｲ \n");
	return 0;
}

int main(){
	int num;
	do{
		scanf("%d",&num);
		switch(num){
			case 0: printf("終了します。\n");break;
			case 1: draw1();break;
			case 2: draw2();break;
			case 3: draw3();break;
			case 4: draw4();break;
			default: printf("1~4以外の数字が入力されました\n");
		}
	}while(num != 0);
    return 0;
}