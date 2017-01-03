// Converter.h
// string型からSEAT_NUMに変換するクラス
// 作成日：2016/6/8
// 作成者：渡邉 翔

#ifndef _CONVERTER_H
#define _CONVERTER_H

#include "Seat.h"
#include <map>
#include <string>
using namespace std;

#define C( str ) converter[string( #str )] = str

class CConverter
{
private:
	// 連想配列
	map<string, SEAT_NUM> converter;

public:
	// コンストラクタ
	CConverter(){
		// 連想配列を初期化
		C(A1); C(A2); C(A3); C(A4); C(A5); C(A6); C(A7); C(A8); C(A9); C(A10); C(A11); C(A12); C(A13);
		C(B1); C(B2); C(B3); C(B4); C(B5); C(B6); C(B7); C(B8); C(B9); C(B10); C(B11); C(B12); C(B13);
		C(C1); C(C2); C(C3); C(C4); C(C5); C(C6); C(C7); C(C8); C(C9); C(C10); C(C11); C(C12); C(C13);
		C(D1); C(D2); C(D3); C(D4); C(D5); C(D6); C(D7); C(D8); C(D9); C(D10); C(D11); C(D12); C(D13);
		C(E1); C(E2); C(E3); C(E4); C(E5); C(E6); C(E7); C(E8); C(E9); C(E10); C(E11); C(E12); C(E13);
	}

	// 連想配列を利用して変換（のつもり）
	SEAT_NUM convert( string str ) {
		return converter[str];
	}
};

#endif