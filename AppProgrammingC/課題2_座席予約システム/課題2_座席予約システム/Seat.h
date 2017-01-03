// Seat.h
// ÀÈ‚ÌƒNƒ‰ƒX
// ì¬“úF2016/5/19
// ì¬ÒF“nç³ ãÄ

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
	SEAT_NUM m_number;	// ÀÈ”Ô†
	bool m_bReserved;			// —\–ñÏ‚İ‚©”Û‚©

public:
	// ƒRƒ“ƒXƒgƒ‰ƒNƒ^
	CSeat(){ m_number = NONE; m_bReserved = false; }
	CSeat( SEAT_NUM num, bool reserved ){ m_number = num; m_bReserved = reserved; }

	// ‰Šú‰»
	void Initialize( SEAT_NUM num, bool reserved ){ m_number = num; m_bReserved = reserved; }

	// —\–ñ
	bool Reserve(){
		if( m_bReserved ) return false; // —\–ñÏ‚İ‚Ìê‡false‚ğ•Ô‚·
		else m_bReserved = true; 
	
		return true;
	}

	// —\–ñƒLƒƒƒ“ƒZƒ‹
	bool Cansel(){
		if( !m_bReserved ) return false; // —\–ñ‚³‚ê‚Ä‚È‚¯‚ê‚Îfalse‚ğ•Ô‚·
		else	m_bReserved = false;
			
		return true;
	}

	// —\–ñó‘Ôæ“¾
	bool GetReserved(){ return m_bReserved; }
};

#endif