#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOM 5

char field[5][5];

int count (int x, int y){
	int n = 0;
	if(x > 0 && y > 0 && field[x-1][y-1] & 0x01) n++;
	if(x > 0 && field[x-1][y] & 0x01) n++;
	if(x > 0 && y < 4 && field[x-1][y+1] & 0x01) n++;
	if(x > 0 && field[x][y-1] & 0x01) n++;
	if(x < 4 && field[x][y+1] & 0x01) n++;
	if(x < 4 && y > 0 && field[x+1][y-1] & 0x01) n++;
	if(x < 4 && field[x+1][y] & 0x01) n++;
	if(x < 4 && y < 4 && field[x+1][y+1] & 0x01) n++;
	return n;
}

int main(){
	int i,j,n,x,y,end = 0;
	int a = 0,b = 0;
	const char num[5][4] = {"0","1","2","3","4"};
	const char alp[5][4] = {"a ","b ","c ","d ","e"};
	char buf[81];

	srand((unsigned int)time(NULL));

	//フィールドの初期化
	for(i = 0;i<5;i++){
		for(j = 0;j<5;j++){
			field[i][j] = 0x00;
		}
	}

	//乱数を使って爆弾を配置
	n = 0;
	while(n < BOM){
		x = rand() % 5;
		y = rand() % 5;
		if(!field[x][y] & 0x01){
			field[x][y] += 0x01;
			n++;
		}
	}

	while(!end){
		system("cls");//コマンドプロンプトの画面をクリア
		printf("  ");
		for(i = 0; i < 5; i++) printf("%s",alp[i]);//画面上の列にabcdeを表示
		printf("\n");
		for(j = 0;j < 5;j++){
			printf("%s",num[j]);//画面左に数字を表示
			for(i = 0;i < 5;i++){
				if(field[i][j] & 0x02){
					n = count(i,j);
					if(n) printf("%s",num[n]);
					else printf("  ");
				}
				else printf("■");
			}
			printf("\n");
		}

		// クリア判定
		n = 0;
		for(i = 0;i<5;i++){
			for(j = 0;j<5;j++){
				if(!field[i][j] & 0x02) n++;
			}
		}
		//入力を求める
		if(n != BOM){
			printf("\nあけるパネルを指定\n");
			scanf("%s",buf);
			x = buf[0] - 'a';
			y = buf[1] - '0';
			if( x >= 0 && x < 5 && y >= 0 && y < 5  && !(field[x][y] & 0x02) ){
				if(field[x][y] & 0x01)end = 2;
				else field[x][y] += 0x02;
			}
			else end = 1;//クリア
		}
	}

	// 終了処理
	system("cls");
	if(end == 1){
		//クリア時の画面表示
		printf("  ");
		for(i = 0;i < 5;i++){
			printf("%s",alp[i]);
		}
		printf("\n");
		for(j = 0;j < 5;j++){
			printf("%s",num[j]);
			for(i = 0;i<5;i++){
				if(field[i][j] & 0x01) printf("●");
				else printf("  ");
			}
			printf("  ");
		}
		printf("\nクリア！\n");
	}else{
		//ゲームオーバー時の画面表示
		printf("  ");
		for(i = 0;i<5;i++){
			printf("\n");
		}
		printf("\n");
		for(j = 0;j<5;j++){
			printf("%s",alp[i]);
		}
		printf("\n");
		for(j =0;j<5;j++){
			printf("%s",num[j]);
			for(i = 0;i<5;i++) printf("＊");
			printf("\n");
		}
		printf("\nゲームオーバー\n");
	}
	return 0;
}