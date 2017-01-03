// SeatManager.h
// 座席を管理するクラス
// 作成日：2016/5/19
// 作成者：渡邉 翔

#ifndef _SEATMANAGER_H
#define _SEATMANAGER_H

#include "Seat.h"
#include <iostream>
using namespace std;

class CSeatManager
{
private:
	CSeat seat[65];					// 座席の配列
	unsigned int m_iVacancy;	// 空席の数
	bool m_bUpdate;					// 更新されたかどうかのフラグ

public:
	// コンストラクタ
	CSeatManager();

	// 座席予約
	// num：座席番号
	// 成功した場合true、失敗した場合falseを返す
	bool Reserve( SEAT_NUM num ){ return seat[num].Reserve(); m_iVacancy--; }

	// 予約キャンセル
	// num：座席番号
	// 成功した場合true、失敗した場合falseを返す
	bool Cansel( SEAT_NUM num ){ return seat[num].Cansel(); m_iVacancy++; }

	// 予約状況確認
	// num：座席番号
	// 座席が予約されていればtrue、されてなければfalseを返す
	bool GetSeatStatus( SEAT_NUM num ) { return seat[num].GetReserved(); }

	// 空席の数を取得
	unsigned int GetVacancyNum(){ return m_iVacancy; }

	// 更新されたかどうかのフラグを取得
	bool GetUpdate(){ return m_bUpdate; }

	// 更新フラグをセット
	// b：更新時にtrue、更新し終えたらfalseをセットするべき
	bool SetUpdate( bool b ){ m_bUpdate = b; }
};

#endif