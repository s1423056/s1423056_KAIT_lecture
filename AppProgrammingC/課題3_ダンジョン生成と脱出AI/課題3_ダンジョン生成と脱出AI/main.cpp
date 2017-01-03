// �ۑ�3_�_���W���������ƒE�oAI
// �쐬���F2016/6/16
//
// main.cpp
// �_���W���������v���O����
//
// �Q�l�E�F�u:
// c����Ŗ��H�Fhttp://studio.s1.xrea.com/prog/maze.html


#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

using namespace std;

enum BLOCK{
	FLOOR,	// ��
	WALL,		//	��
	START,		// �X�^�[�g
	GOAL,		// �S�[��
	ROOT,		// �_�~�[
	PLAYER	// �T���ʒu
};

const int sizeX = 100;
const int sizeY = 100;

int X[sizeX*sizeY];
int Y[sizeX*sizeY];

BLOCK map[sizeY][sizeX];	// �_���W�����}�b�v

// �@��i�߂�֐�
void dig( int x, int y )
{
	int dx, dy, r;			// �����ƃ����_���̕ϐ�
	int count = 0;		// �J�E���^
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
		// �@��������ǂ��A2�}�X�悪�ǂłȂ��ꍇ�A�J�E���^����
		if( x + dx*2 <= 0 || x + dx*2 >= sizeX-1 ||
			y + dy*2 <= 0 || y + dy*2 >= sizeY-1 ||	
			map[y+dy*2][x+dx*2] != WALL ) count++;
		else if( map[y+dy*2][x+dx*2] == WALL ){// �@�������ɍ��v
			map[y+dy][x+dx] = map[y+dy*2][x+dx*2] = FLOOR;
			x = x + dx*2;
			y = y + dy*2;
			count = 0;
			r = rand();
		}
	}
}

// ���C���֐�
int main(){
	// �}�b�v������
	// �܂��S�Ă�ǂŖ��߂�
	for( int y = 0; y < sizeY; y++ ){
		for( int x = 0; x < sizeX; x++ ){
			map[y][x] = WALL;
		}
	}

	// ����[����@��n�߂�
	map[1][1] = FLOOR;
	while( 1 ){
		int i = 0;
		for( int y = 1; y < sizeY - 1; y += 2 ){
			for( int x = 1; x < sizeX - 1; x += 2 ){
				if( map[y][x] == FLOOR ){	// ������@��n�߂�
					// 2�}�X�悪�O�ǈȊO�̕ǂ̏ꍇ�A
					if( ( x-2 >= 0 && map[y][x-2] == WALL ) || ( y-2 >= 0 && map[y-2][x] == WALL ) || 
						( x+2 < sizeX-1 && map[y][x+2] == WALL ) || ( y+2 < sizeY-1 && map[y+2][x] == WALL ) ){
						X[i] = x;	// �@��i�߂���Ƃ���
						Y[i] = y;
						i++;
					}else if( ( y == sizeY-2 ) && ( x == sizeX - 2) ) break;
				}
			}
		}
		if( i == 0 ) break;	// ���Ȃ�
		else{
			srand((unsigned)time(NULL));
			int d = rand() % i;// ���̒����烉���_���Ō@��
			int x = X[d];
			int y = Y[d];
			dig( x, y );
		}
	}

	// �c1��E�Ɋg��
	for( int x = sizeX - 2; x >= sizeX / 2; x-- ){
		for( int y = sizeY - 2; y > 0; y-- ){
			map[x][y] = map[x-1][y];
			// ����2��ɂȂ�Ȃ��悤�ɂ���
			if( x == sizeX/2 && map[x-2][y] == WALL && map[x-1][y] == FLOOR && map[x][y] == FLOOR )
				map[x-1][y] = WALL;
		}
	}

	// ��1�񉺂Ɋg��
	for( int y = sizeY - 2; y >= sizeY / 2; y-- ){
		for( int x = sizeX - 2; x > 0; x-- ){
			map[x][y] = map[x][y-1];
			// ����2��ɂȂ�Ȃ��悤�ɂ���
			if( y == sizeY/2 && map[x][y-2] == WALL && map[x][y-1] == FLOOR && map[x][y] == FLOOR )
				map[x][y-1] = WALL; 
		}
	}

	// �X�^�[�g�ʒu�ݒ�
	int sx, sy;
	do{
		sx = rand() % (sizeX-2) + 1;
		sy = rand() % (sizeY-2) + 1;
	}while( map[sx][sy] != FLOOR ); // �ʘH��ɐݒ肳��Ȃ����胋�[�v
	map[sy][sx] = START;
	
	// �S�[���ʒu�ݒ�
	int gx, gy;
	do{
		gx = rand() % (sizeX-2) + 1;
		gy = rand() % (sizeY-2) + 1;
	}while( map[gx][gy] != FLOOR ); // �ʘH��ɐݒ肳��Ȃ����胋�[�v
	map[gy][gx] = GOAL;

	// �t�@�C���o��
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