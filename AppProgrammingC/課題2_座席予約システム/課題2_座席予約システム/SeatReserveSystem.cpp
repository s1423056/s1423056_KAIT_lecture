// SeatReserveSystem.cpp
// 座席予約管理システムのクラス
// 作成日：2016/6/7
// 作成者：渡邉 翔

#include "SeatReserveSystem.h"
#include <Windows.h>

// ファイル読み込みマクロ
#define Import( filename ) { fileManager.ImportFile( filename, &seatManager ); }

// コンストラクタ
CSeatReserveSystem::CSeatReserveSystem() : UI( &seatManager, &converter ), fileManager( &converter )
{
	Update();
}

// ファイルを読み込んで状態を更新
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

// 予約実行
void CSeatReserveSystem::Reserve()
{
	Update();	// 状態更新
	UserData data = UI.Input();	// 予約データ入力

	// ファイル出力
	list<string>::iterator ite;
	for( ite = data.seatList.begin(); ite != data.seatList.end(); ite++ ){
		string str = (*ite);
		str += ".txt";
		fileManager.ExportFile( str, data );
	}
}

// キャンセル実行
void CSeatReserveSystem::Cansel()
{
	string name = UI.InputName();
	string seatNum = UI.InputSeatNum();
	SEAT_NUM num =  converter.convert( seatNum );
	string targetName = fileManager.ImportFile( seatNum );
	if( name == targetName ){ // 入力した名前とファイルに書かれた名前を比較
		seatManager.Cansel( num );
		string filenameStr = seatNum + ".txt";
		LPCSTR filename = filenameStr.c_str();

		if ( DeleteFile( "A1.txt" ) ){	// ファイル削除
			Update();
			cout << "座席番号" << seatNum << "の座席の予約をキャンセルできませんでした。" << endl;
		}
		else{
			Update();
			cout << "座席番号" << seatNum << "の座席の予約をキャンセルできませんでした。" << endl;
		}
	}
	else{
		Update();
		cout << "名前が一致している座席がありません。" << endl;
	}
}

// 実行
void CSeatReserveSystem::Run()
{
	while( 1 ){
		Update();	// 状態更新

		cout << "rキー：予約開始  cキー：キャンセル開始  qキー：終了" << endl;
		cout << "コマンドを入力してください。：" ;
		string cmd;	 // コマンド
		cin >> cmd; // コマンド入力
	
		if( cmd == "r" ){
			cout << "予約を開始します。" << endl;
			Reserve();	// 予約実行
			Sleep( 2000 );
		}
		
		if( cmd == "c" ){
			cout << "予約をキャンセルします。" << endl;
			Cansel();		// キャンセル開始
			Sleep( 2000 );
		}

		if( cmd == "q" ){
			cout << "終了します。ありがとうございました。" << endl;
			Sleep( 2000 );
			break;			// 終了
		}
	}
}