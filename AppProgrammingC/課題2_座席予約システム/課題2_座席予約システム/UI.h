// UI.h
// ユーザーインターフェイス
// 作成日：2016/6/7
// 作成者：渡邉 翔

#ifndef _UI_H
#define _UI_H

#include "UserInput.h"
#include "Display.h"
#include "Converter.h"

using namespace std;

class CUserInterface
{
private:
	CUserInput input;	// 入力
	CDisplay display;		// 画面表示クラス

public:
	// コンストラクタ
	// seatM：座席管理クラスのポインタ
	// converter：stringをSEAT_NUMに変換するクラスのポインタ
	CUserInterface( CSeatManager* seatM, CConverter* converter );

	// 画面表示
	void Display();

	// ユーザー入力
	UserData Input();

	// ユーザー名入力
	string InputName(){ return input.InputName(); }

	// 座席番号入力
	string InputSeatNum(){ return input.InputSeatNum(); }

};

#endif