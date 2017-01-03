// SeatManager.cpp
// 座席を管理するクラス
// 作成日：2016/5/19
// 作成者：渡邉 翔

#include "SeatManagar.h"

// コンストラクタ
CSeatManager::CSeatManager()
{
	// 数値の初期化
	for( int i = A1; i < NONE; i++ ){
		seat[i].Initialize( (SEAT_NUM)i, false );
	}
	m_iVacancy = NONE;
}