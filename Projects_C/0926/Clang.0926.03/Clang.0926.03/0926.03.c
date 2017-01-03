//導入ユニット　C言語　問題３　【宿題レポート】これは授業時間に実施しません。宿題として自宅でゆっくり学習しましょう。次のプログラムを入力・実行しなさい。レポート作成方法に倣い、問題１・２で作成したファイルに追加しなさい。
//1423056　渡邉　翔　2014/09/26

#include<stdio.h>
#include<conio.h>

void functionS();

int main() {
			int key=0, key2=0;
			do {
						if  (kbhit()) {
									key=getch();
									//printf("%x\n", key);

									switch(key) {
												case 0xe0:	printf("矢印の");
																	key2 = getch();
																	switch(key2){
																			case 0x4b:		printf("左\n");				break;
																			case 0x4d:		printf("右\n");				break;
																			case 0x48:		printf("上\n");				break;
																			case 0x50:		printf("下\n");				break;					
																	}break;
												case 'a':		printf("aです\n");			break;
												case 's':		functionS();						break;
												case 'd':		printf("dです\n");			break;
												case 'A':		printf("Aです\n");			break;
												case 'q':		printf("qで終了\n");			break;
												default:		printf("そのキーは利用できません[q]	を押すと終了\n");
									}
						}
			}while(key!='q');
			printf("お疲れ様でした\n\n");
			return 0;
}

void functionS(){
			printf("\n");
			printf("エスです\n");
			printf("\n");
			return ;
}