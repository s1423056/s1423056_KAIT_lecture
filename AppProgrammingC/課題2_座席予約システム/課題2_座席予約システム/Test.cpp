// Test.cpp
// �e�X�g���s��

#include "Test.h"
#include <Windows.h>
#include <locale>
#include <codecvt>

#pragma warning( disable: 4996 )

#define Import( filename ) { fileManager.ImportFile( filename, &seatManager ); }

CTest::CTest() : ui( &seatManager, &converter ), fileManager( &converter )
{
	Update();
}

void CTest::Update(){
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
	ui.Display();
}

void CTest::Cansel()
{
	string name = ui.InputName();
	string seatNum = ui.InputSeatNum();
	SEAT_NUM num =  converter.convert( seatNum );
	string targetName = fileManager.ImportFile( seatNum );
	if( name == targetName ){
		seatManager.Cansel( num );
		string filenameStr = seatNum + ".txt";

		wstring_convert<std::codecvt_utf8<wchar_t>,wchar_t> cv;

		wstring str = cv.from_bytes(filenameStr);
		LPCTSTR filename = str.c_str();

		if ( DeleteFile( filename ) ){
			cout << "�t�@�C�����폜" << endl;
		}	// �t�@�C���폜
		
		Update();
		cout << "���Ȕԍ�" << seatNum << "�̍��Ȃ̗\����L�����Z�����܂����B" << endl;
	}
}

void CTest::Run()
{
	while( 1 ){
		
		cout << "r�L�[�F�\��J�n  c�L�[�F�L�����Z���J�n  q�L�[�F�I��" << endl;
		cout << "�R�}���h����͂��Ă��������F";
		string c;
		cin >> c;

		if( c == "r" ){
			ui.Display();
			cout << "�\����J�n���܂��B" << endl;
			UserData data = ui.Input();
			list<string>::iterator ite;
			for( ite = data.seatList.begin(); ite != data.seatList.end(); ite++ ){
				string str = (*ite);
				str += ".txt";
				fileManager.ExportFile( str, data );
			}
		}
		
		else if( c == "c" ){
			ui.Display();
			cout << "�\����L�����Z�����܂��B" << endl;
			Cansel();
		}
		
		else if( c == "q" ){
			cout << "�I�����܂��B���肪�Ƃ��������܂����B" << endl;
			Sleep( 3000 );
			break;
		}else{
			cout << "���͂��s���ł��B������x��蒼���Ă��������B" << endl;
		}

	}
}