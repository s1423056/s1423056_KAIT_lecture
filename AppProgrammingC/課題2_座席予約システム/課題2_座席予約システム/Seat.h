// Seat.h
// 座席のクラス
// 作成日：2016/5/19
// 作成者：渡邉 翔

#ifndef _SEAT_H
#define _SEAT_H

enum SEAT_NUM
{
	A1 = 1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13,
	B1, B2, B3, B4, B5,B6, B7, B8, B9, B10, B11, B12, B13,
	C1, C2, C3, C4, C5, C6, C7, C8, C9, C10, C11, C12, C13,
	D1, D2, D3, D4,D5, D6, D7, D8, D9, D10, D11, D12, D13,
	E1, E2, E3, E4, E5, E6, E7, E8, E9, E10, E11, E12, E13,
	NONE
};

class CSeat
{
private:
	SEAT_NUM m_number;	// 座席番号
	bool m_bReserved;			// 予約済みか否か

public:
	// コンストラクタ
	CSeat(){ m_number = NONE; m_bReserved = false; }
	CSeat( SEAT_NUM num, bool reserved ){ m_number = num; m_bReserved = reserved; }

	// 初期化
	void Initialize( SEAT_NUM num, bool reserved ){ m_number = num; m_bReserved = reserved; }

	// 予約
	bool Reserve(){
		if( m_bReserved ) return false; // 予約済みの場合falseを返す
		else m_bReserved = true; 
	
		return true;
	}

	// 予約キャンセル
	bool Cansel(){
		if( !m_bReserved ) return false; // 予約されてなければfalseを返す
		else	m_bReserved = false;
			
		return true;
	}

	// 予約状態取得
	bool GetReserved(){ return m_bReserved; }
};

#endif