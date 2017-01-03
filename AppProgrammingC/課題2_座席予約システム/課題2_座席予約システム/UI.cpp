// UI.cpp
// ユーザーインターフェイス
// 作成日：2016/6/7
// 作成者：渡邉 翔

#include "UI.h"
#include <iostream>
using namespace std;

// コンストラクタ
CUserInterface::CUserInterface( CSeatManager* seatM, CConverter* converter )
	: display( seatM ), input( seatM, &display, converter )
{}

// 画面表示
void CUserInterface::Display()
{
	display.Display();
}

// ユーザー入力
UserData CUserInterface::Input()
{
	UserData data = input.Input();
	return data;
}