// UserInput.h
// ユーザーからの入力を管理するクラス
// 作成日：2016/6/8
// 作成者：渡邉 翔

#ifndef _USERINPUT_H
#define _USERINPUT_H

#include <string>
#include <list>
#include <map>
#include "Converter.h"
#include "SeatManagar.h"
#include "Display.h"
using namespace std;

struct UserData
{
	string name;						// 名前
	unsigned int num;				// 予約した座席数
	list<string> seatList;			// 予約した座席番号のリスト
};

class CUserInput
{
private:
	CSeatManager* seatManager;	// 座席管理クラスのポインタ
	CDisplay* display;				// 画面表示クラスのポインタ
	CConverter* converter;		// stringからSEAT_NUMへ変換するクラスのポインタ
	
	// 座席数入力
	// 入力された数値を返す
	int InputNum();

	// 座席番号入力
	// seatStr：確認のために座席番号を格納する文字列のポインタ
	SEAT_NUM InputSeatNum( string* seatStr );	
	
	// 入力まとめ
	// data：入力データのポインタ
	void InputDataSet( UserData* data );

public:
	// コンストラクタ
	// seatM：座席管理クラスのポインタ
	CUserInput( CSeatManager* seatM, CDisplay* disp, CConverter* converter );

	// 外部から呼び出すユーザー入力関数
	UserData Input();
	
	// 名前入力
	// 入力された文字列を返す
	string InputName();

	// 座席番号入力（だけ）
	string InputSeatNum();
};

#endif