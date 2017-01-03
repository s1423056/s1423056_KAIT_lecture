// UserInput.cpp
// ユーザーからの入力を管理するクラス
// 作成日：2016/6/8
// 作成者：渡邉 翔

#include "UserInput.h"

#define C( str ) converter[string( #str )] = str

// コンストラクタ
CUserInput::CUserInput( CSeatManager* seatM, CDisplay* disp, CConverter* converter )
	: seatManager( seatM ), display( disp ), converter( converter )
{}

// 名前入力
string CUserInput::InputName()
{
	string str;		// 名前を格納する文字列変数
	cout << "名前を入力してください。：";
	cin >> str;	// 入力
	return str;
}

// 座席数入力
int CUserInput::InputNum()
{
	int num;	// 予約する座席数を格納する変数
	bool loop = true;	// 不正入力時のループ変数

	cout << "予約する座席の数を入力してください。：";
	do{
		if( !( cin >> num ) ){ // 0以下または空席以上の数値の場合
			cin.clear();
			cin.ignore( INT_MAX, '\n' );
			cout << "値が不正です。もう一度やり直してください。" << endl
					<< "予約する座席の数を入力してください。：";
		}else loop = false;
	}while( loop );

	return num;
}

// 座席番号入力
SEAT_NUM CUserInput::InputSeatNum( string* seatStr )
{
	bool loop = true;			// 不正入力時のループ用の変数
	SEAT_NUM seatNum;	// 座席番号を格納する変数
	string str;						// 入力を受け取る変数
	
	do{
		cout << "予約する座席の番号を入力してください。" << endl
				<< "入力例" << endl 
				<< "C列の3番を予約したい場合：C3" << endl
				<< "座席番号：";
		cin >> str;	// 入力を受け取る
		*seatStr = str;	// 出力用の変数に文字列を代入
		seatNum = converter -> convert( str );	// 文字列をSEAT_NUM型に変換
		if( seatNum <= 0 || seatNum >= NONE ){	// 不正入力の場合
			display -> Display();	// 画面更新
			cout << "入力された番号が不正です。" << endl
					<< "入力内容を確認の上、もう一度入力してください" << endl;
		}else loop = false;	// 成功時にループを抜ける
	}while( loop );

	return seatNum;
}

// 座席番号入力(だけ)
string CUserInput::InputSeatNum()
{
	bool loop = true;			// 不正入力時のループ用の変数
	SEAT_NUM seatNum;	// 座席番号を格納する変数
	string str;						// 入力を受け取る変数
	
	do{
		cout << "座席の番号を入力してください。" << endl
				<< "入力例" << endl 
				<< "C列の3番の場合：C3" << endl
				<< "座席番号：";
		cin >> str;	// 入力を受け取る
		
		seatNum = converter -> convert( str );	// 文字列をSEAT_NUM型に変換
		if( seatNum <= 0 || seatNum >= NONE ){	// 不正入力の場合
			display -> Display();	// 画面更新
			cout << "入力された番号が不正です。" << endl
					<< "入力内容を確認の上、もう一度入力してください" << endl;
		}else loop = false;	// 成功時にループを抜ける
	}while( loop );

	return str;
}

// 入力まとめ
void CUserInput::InputDataSet( UserData* data )
{
	// 名前を入力
	string name = InputName();
	data -> name = name;

	// 座席数を入力
	int num = InputNum();
	data -> num = num;

	// 入力した座席数だけループ
	for( int i = 1; i <= num; i++ ){
		bool loop = true;	// 失敗時ループするためのフラグ
		string seatNum;	// 確認用の座席番号を格納する文字列

		do{	// 座席予約ができるまでループ
			cout << num << "席中" << i << "席目の座席番号を入力" << endl;

			// 予約する座席の番号を入力
			SEAT_NUM seat = InputSeatNum( &seatNum );

				if( !seatManager -> Reserve( seat ) ){
					// 予約失敗時
					display -> Display();	// 画面更新
					cout << "座席番号" << seatNum << "の座席は既に予約されています。" << endl;
					
				}else{
					// 予約成功時
					display -> Display();	// AA表示更新
					cout << "=================================" << endl
							<< "名前" << name << "で" << endl
							<< "座席番号 " << seatNum << " の座席を予約しました。" << endl
							<< "=================================" << endl << endl;
					data -> seatList.push_back( seatNum );	// 入力データに座席リストをセット
					loop = false;	// ループを抜ける
				}

		}while( loop );
	}
}

// 外部から呼び出す関数
UserData CUserInput::Input()
{
	UserData data;
	InputDataSet( &data );
	return data;
}