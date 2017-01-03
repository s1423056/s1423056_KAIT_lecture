// SeatReserveSystem.cpp
// ���ȗ\��Ǘ��V�X�e���̃N���X
// �쐬���F2016/6/7
// �쐬�ҁF�n� ��

#include "SeatReserveSystem.h"
#include <Windows.h>

// �t�@�C���ǂݍ��݃}�N��
#define Import( filename ) { fileManager.ImportFile( filename, &seatManager ); }

// �R���X�g���N�^
CSeatReserveSystem::CSeatReserveSystem() : UI( &seatManager, &converter ), fileManager( &converter )
{
	Update();
}

// �t�@�C����ǂݍ���ŏ�Ԃ��X�V
void CSeatReserveSystem::Update()
{
	string filename;
	for( int i = 1; i <= 13; i++ ){
		filename = "A" + to_string( i ) + ".txt";
		Import( filename );

		filename = "B" + to_string( i ) + ".txt";
		Import( filename );

		filename = "C" + to_string( i ) + ".txt";
		Import( filename );

		filename = "D" + to_string( i ) + ".txt";
		Import( filename );
		
		filename = "E" + to_string( i ) + ".txt";
		Import( filename );
	}
	UI.Display();
}

// �\����s
void CSeatReserveSystem::Reserve()
{
	Update();	// ��ԍX�V
	UserData data = UI.Input();	// �\��f�[�^����

	// �t�@�C���o��
	list<string>::iterator ite;
	for( ite = data.seatList.begin(); ite != data.seatList.end(); ite++ ){
		string str = (*ite);
		str += ".txt";
		fileManager.ExportFile( str, data );
	}
}

// �L�����Z�����s
void CSeatReserveSystem::Cansel()
{
	string name = UI.InputName();
	string seatNum = UI.InputSeatNum();
	SEAT_NUM num =  converter.convert( seatNum );
	string targetName = fileManager.ImportFile( seatNum );
	if( name == targetName ){ // ���͂������O�ƃt�@�C���ɏ����ꂽ���O���r
		seatManager.Cansel( num );
		string filenameStr = seatNum + ".txt";
		LPCSTR filename = filenameStr.c_str();

		if ( DeleteFile( "A1.txt" ) ){	// �t�@�C���폜
			Update();
			cout << "���Ȕԍ�" << seatNum << "�̍��Ȃ̗\����L�����Z���ł��܂���ł����B" << endl;
		}
		else{
			Update();
			cout << "���Ȕԍ�" << seatNum << "�̍��Ȃ̗\����L�����Z���ł��܂���ł����B" << endl;
		}
	}
	else{
		Update();
		cout << "���O����v���Ă�����Ȃ�����܂���B" << endl;
	}
}

// ���s
void CSeatReserveSystem::Run()
{
	while( 1 ){
		Update();	// ��ԍX�V

		cout << "r�L�[�F�\��J�n  c�L�[�F�L�����Z���J�n  q�L�[�F�I��" << endl;
		cout << "�R�}���h����͂��Ă��������B�F" ;
		string cmd;	 // �R�}���h
		cin >> cmd; // �R�}���h����
	
		if( cmd == "r" ){
			cout << "�\����J�n���܂��B" << endl;
			Reserve();	// �\����s
			Sleep( 2000 );
		}
		
		if( cmd == "c" ){
			cout << "�\����L�����Z�����܂��B" << endl;
			Cansel();		// �L�����Z���J�n
			Sleep( 2000 );
		}

		if( cmd == "q" ){
			cout << "�I�����܂��B���肪�Ƃ��������܂����B" << endl;
			Sleep( 2000 );
			break;			// �I��
		}
	}
}