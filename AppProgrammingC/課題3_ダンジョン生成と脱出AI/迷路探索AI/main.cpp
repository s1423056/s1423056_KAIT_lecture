// �ۑ�3_�_���W���������ƒE�oAI
// �쐬���F2016/6/29
//
// main.cpp
// �E�o�o�H�T���v���O����
//
// �Q�l�E�F�u:
// c����Ŗ��H�Fhttp://studio.s1.xrea.com/prog/maze.html
// �_�u���o�b�t�@�����O�Fhttp://tama012.blogspot.jp/2012/11/blog-post.html
//										http://vivi.dyndns.org/tech/cpp/DblBuffer.html

#include <fstream>
#include <iostream>
using namespace std;

#include "DoubleBufferConsole.h"

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

BLOCK map[sizeY][sizeX];	// �_���W�����}�b�v
DoubleBufferConsole db;	// �_�u���o�b�t�@�R���\�[��

bool clear = false;				// �S�[���������ǂ���

// �X�V���x���[�h(�`��Ȃ��A�����A�ᑬ)
enum UpdateMode{
	NODRAW, FAST, NORMAL
}mode;

// �v���g�^�C�v�錾
void Draw( int, int );
bool Check( int, int );
void Root( int, int );

// �}�b�v�`��
void Draw( int posY, int posX ){
	if( mode == NODRAW ) return;
	db.SetCursorPos( 0, 0 );

	int row = 0;	// �`�悷��s��
	for( int y = posY-10; y < posY+10; y++ ){ // �����Ŏw�肵��y���W�̏㉺10�s����`��
		if( y < 0 || y >= sizeY ) for( int i = 0; i < 20;i++ ) db.Write( "�~" ); // �O���́~��\��
		else{
			for( int x = posX-10; x < posX+10; x++ ){ // �����Ŏw�肵��x���W�̍��E10�񕪂�`��
				if( x < 0 || x >= sizeX ) db.Write( "�~" ); // �O���́~��\��
				else {
					switch( map[y][x] ){
						case FLOOR: db.Write( "�@" ); break; // ��
						case WALL: db.Write( "��" ); break; // ��
						case START: db.Write( "�r" ); break; // �X�^�[�g
						case GOAL: db.Write( "�f" ); break; // �S�[��
						case PLAYER: db.Write( "�E" ); break; // �T���ʒu
						default: db.Write( "�H" ); break;		// �O�̂���
					}
				}
			}
		}
		// ���s
		row++;	
		db.SetCursorPos( 0, row );
	}

	if( mode == FAST )Sleep( 10 );	// 1/1000�b�҂�
	else Sleep( 500 );	// 1/2�b�҂�
	db.Swap();	// �o�b�t�@���X���b�v���ĉ�ʂɕ\��
}

// �㉺���E�ǂꂩ�ׂɃS�[�������邩
bool CheckAround( int posY, int posX ){
	if( map[posY][posX-1] == GOAL || map[posY][posX+1] == GOAL ||
		map[posY-1][posX] == GOAL || map[posY+1][posX] == GOAL ){
		if( mode != NODRAW )Sleep( 2000 );	// 2�b�҂�
		return true;
	}
	else return false;
}

// �T��
void Root( int y, int x ){
	if( clear ) return;
	if( map[y][x] == FLOOR ) {
		map[y][x] = PLAYER;
		Draw( y, x );
	}

	// ���݈ʒu�̎���ɃS�[�����Ȃ��ꍇ
	if( CheckAround( y, x ) ){
		clear = true;
		return;
	}else{
		// �㉺���E���ꂼ��i�߂�ꏊ������ΐi��
		if( map[y-1][x] == FLOOR ){
			Root( y-1, x );
		}
		if( map[y+1][x] == FLOOR ){
			Root( y+1, x );
		}
		if( map[y][x-1] == FLOOR ){
			Root( y, x-1 );
		}
		if( map[y][x+1] == FLOOR ){
			Root( y, x+1 );
		}
	}
}

// ���C���֐�
int main(){
	db.Write( "���[�h��I��\n" );
	db.Write( "0:�`��Ȃ��i�t�@�C���o�͂̂݁j\n1:�����`�惂�[�h\n2:�ʏ탂�[�h\n " );
	db.Swap();
	int num;
	cin >> num;
	switch( num ){
		case 0: 
			mode = NODRAW;
			db.Write( "�`��Ȃ��Ŏ��s���܂��B\n" );
			break;
		case 1: 
			mode = FAST; 
			db.Write( "�����`�惂�[�h�Ŏ��s���܂��B\n" );
			break;
		case 2:
			mode = NORMAL;
			db.Write( "�ʏ탂�[�h�Ŏ��s���܂��B\n" );
			break;
		default: 
			mode = NORMAL;
			db.Write( "���͂��s���ł��B�ʏ탂�[�h�Ŏ��s���܂��B\n" );
			break;
	}
	db.Swap();
	Sleep( 1000 );	// 1�b�҂�

	// �t�@�C���ǂݍ���
	ifstream ifs;
	ifs.open( "maze.txt" );
	if( ifs.fail() ){
		cout << "�t�@�C�����J���܂���ł����B" << endl;
		return -1;
	}

	string str;	// �ǂݍ��񂾕�������i�[����o�b�t�@
	int x = 0, y = 0;	// �}�b�v�𐶐�����}�X�ڂ̍��W
	int sx, sy, gx, gy;	// �X�^�[�g�A�S�[���ʒu�̍��W
	while( getline( ifs, str ) ){	//	1�s���ǂݍ��݁A�t�@�C���̍Ō�܂Ń��[�v
		for( int i = 0; i < str.size(); i++ ){	// 1���������
			switch( str[i] ){
				case '0':	// ��
					map[y][x] = FLOOR;
					break;
				case '1':	// ��
					map[y][x] = WALL;
					break;
				case '2':	// �X�^�[�g
					map[y][x] = START;
					sx = x; sy = y;
					break;
				case '3':	// �S�[��
					map[y][x] = GOAL;
					gx = x; gy = y;
					break;
				default:
					x--;	// �󔒂�ǂݍ��񂾏ꍇ��x���֖߂�
			}
			x++;	// �E�̃}�X�֐i��
		}
		x = 0;		// ���s
		y++;
	}

	// �X�^�[�g�ʒu����T���J�n
	Root( sy, sx );

	// ���ʃe�L�X�g�o��
	ofstream ofs;
	ofs.open( "ans.txt" );
	if( ofs.fail() ){
		cout << "�t�@�C�����J���܂���" << endl;
		return -1;
	}
	// �}�b�v��Ђ��[���珑���o��
	for( int y = 0; y < sizeY; y++ ){
		for( int x = 0; x < sizeX; x++ ){
			ofs << map[y][x];
			ofs << " ";
		}
		ofs << endl;	// 1�s�I���������s
	}
	ofs.close();

	return 0;
}