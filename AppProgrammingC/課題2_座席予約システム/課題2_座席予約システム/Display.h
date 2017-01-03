// Display.h
// 画面の表示を行うクラス

#ifndef _DISPLAY_H
#define _DISPLAY_H

#include "SeatManagar.h"
#include <string>
using namespace std;

class CDisplay
{
private:
	CSeatManager* seatManager;// 座席管理オブジェクトのポインタ

	// 予約状況取得を文字に変換する関数
	string G( SEAT_NUM num ){
		if( seatManager -> GetSeatStatus( num ) )
			return "×";
		else
			return "○";
	}

public:
	// コンストラクタ
	CDisplay( CSeatManager* seatM ) : seatManager( seatM ){};

	// 予約状況表示
	void Display();
};

#endif