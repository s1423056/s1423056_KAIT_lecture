// 課題3_ダンジョン生成と脱出AI
// 作成日：2016/6/16
//
// main.cpp
// ダンジョン生成プログラム
//
// 参考ウェブ:
// c言語で迷路：http://studio.s1.xrea.com/prog/maze.html


#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

using namespace std;

enum BLOCK{
	FLOOR,	// 床
	WALL,		//	壁
	START,		// スタート
	GOAL,		// ゴール
	ROOT,		// ダミー
	PLAYER	// 探索位置
};

const int sizeX = 100;
const int sizeY = 100;

int X[sizeX*sizeY];
int Y[sizeX*sizeY];

BLOCK map[sizeY][sizeX];	// ダンジョンマップ

// 掘り進める関数
void dig( int x, int y )
{
	int dx, dy, r;			// 方向とランダムの変数
	int count = 0;		// カウンタ
	r = rand();
	while( count < 4 ){
		switch( ( r + 4 + count ) % 4 ){
		case 0:
			dx = 0; dy = -1;
			break;
		case 1:
			dx = -1; dy = 0;
			break;
		case 2:
			dx = 0; dy = 1;
			break;
		case 3:
			dx = 1; dy = 0;
			break;
		}
		// 掘る方向が壁か、2マス先が壁でない場合、カウンタ増加
		if( x + dx*2 <= 0 || x + dx*2 >= sizeX-1 ||
			y + dy*2 <= 0 || y + dy*2 >= sizeY-1 ||	
			map[y+dy*2][x+dx*2] != WALL ) count++;
		else if( map[y+dy*2][x+dx*2] == WALL ){// 掘れる条件に合致
			map[y+dy][x+dx] = map[y+dy*2][x+dx*2] = FLOOR;
			x = x + dx*2;
			y = y + dy*2;
			count = 0;
			r = rand();
		}
	}
}

// メイン関数
int main(){
	// マップ初期化
	// まず全てを壁で埋める
	for( int y = 0; y < sizeY; y++ ){
		for( int x = 0; x < sizeX; x++ ){
			map[y][x] = WALL;
		}
	}

	// 左上端から掘り始める
	map[1][1] = FLOOR;
	while( 1 ){
		int i = 0;
		for( int y = 1; y < sizeY - 1; y += 2 ){
			for( int x = 1; x < sizeX - 1; x += 2 ){
				if( map[y][x] == FLOOR ){	// 床から掘り始める
					// 2マス先が外壁以外の壁の場合、
					if( ( x-2 >= 0 && map[y][x-2] == WALL ) || ( y-2 >= 0 && map[y-2][x] == WALL ) || 
						( x+2 < sizeX-1 && map[y][x+2] == WALL ) || ( y+2 < sizeY-1 && map[y+2][x] == WALL ) ){
						X[i] = x;	// 掘り進める候補とする
						Y[i] = y;
						i++;
					}else if( ( y == sizeY-2 ) && ( x == sizeX - 2) ) break;
				}
			}
		}
		if( i == 0 ) break;	// 候補なし
		else{
			srand((unsigned)time(NULL));
			int d = rand() % i;// 候補の中からランダムで掘る
			int x = X[d];
			int y = Y[d];
			dig( x, y );
		}
	}

	// 縦1列右に拡張
	for( int x = sizeX - 2; x >= sizeX / 2; x-- ){
		for( int y = sizeY - 2; y > 0; y-- ){
			map[x][y] = map[x-1][y];
			// 床が2列にならないようにする
			if( x == sizeX/2 && map[x-2][y] == WALL && map[x-1][y] == FLOOR && map[x][y] == FLOOR )
				map[x-1][y] = WALL;
		}
	}

	// 横1列下に拡張
	for( int y = sizeY - 2; y >= sizeY / 2; y-- ){
		for( int x = sizeX - 2; x > 0; x-- ){
			map[x][y] = map[x][y-1];
			// 床が2列にならないようにする
			if( y == sizeY/2 && map[x][y-2] == WALL && map[x][y-1] == FLOOR && map[x][y] == FLOOR )
				map[x][y-1] = WALL; 
		}
	}

	// スタート位置設定
	int sx, sy;
	do{
		sx = rand() % (sizeX-2) + 1;
		sy = rand() % (sizeY-2) + 1;
	}while( map[sx][sy] != FLOOR ); // 通路上に設定されない限りループ
	map[sy][sx] = START;
	
	// ゴール位置設定
	int gx, gy;
	do{
		gx = rand() % (sizeX-2) + 1;
		gy = rand() % (sizeY-2) + 1;
	}while( map[gx][gy] != FLOOR ); // 通路上に設定されない限りループ
	map[gy][gx] = GOAL;

	// ファイル出力
	ofstream ofs;
	ofs.open( "maze.txt" );
	for( int y = 0; y < sizeY; y++ ){
		for( int x = 0; x < sizeX; x++ ){
			switch( map[y][x] ){
				case FLOOR:
					ofs << "0";
					break;
				case WALL:
					ofs << "1";
					break;
				case START:
					ofs << "2";
					break;
				case GOAL:
					ofs << "3";
					break;
			}
			ofs << " ";
		}
		ofs << endl;
	}

	ofs.close();	
	return 0;
}