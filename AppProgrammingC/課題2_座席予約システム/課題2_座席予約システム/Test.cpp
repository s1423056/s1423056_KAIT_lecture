// Test.cpp
// テストを行う

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
			cout << "ファイルを削除" << endl;
		}	// ファイル削除
		
		Update();
		cout << "座席番号" << seatNum << "の座席の予約をキャンセルしました。" << endl;
	}
}

void CTest::Run()
{
	while( 1 ){
		
		cout << "rキー：予約開始  cキー：キャンセル開始  qキー：終了" << endl;
		cout << "コマンドを入力してください：";
		string c;
		cin >> c;

		if( c == "r" ){
			ui.Display();
			cout << "予約を開始します。" << endl;
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
			cout << "予約をキャンセルします。" << endl;
			Cansel();
		}
		
		else if( c == "q" ){
			cout << "終了します。ありがとうございました。" << endl;
			Sleep( 3000 );
			break;
		}else{
			cout << "入力が不正です。もう一度やり直してください。" << endl;
		}

	}
}