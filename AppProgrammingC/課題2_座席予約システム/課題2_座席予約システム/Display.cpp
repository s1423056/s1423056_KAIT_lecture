// Display.cpp
// ��ʂ̕\�����s���N���X

#include "Display.h"

void CDisplay::Display()
{
	if( seatManager == NULL ) return;
	system( "cls" );
	cout << "****************���ȗ\���****************" << endl<< endl;
	cout << "  | �P �Q �R �S �T �U �V �W �X 10 11 12 13" << endl;
	cout << "============================================" << endl;
	cout << "E | " << G( E1 ) << " " << G( E2 ) << " " << G( E3 ) << " " << G( E4 ) << " " << G( E5 ) << " " << G( E6 ) << " " 
		<< G( E7 ) << " " << G( E8 ) << " " << G( E9 ) << " " << G( E10 ) << " " << G( E11 ) << " " << G( E12 ) << " " << G( E13 ) << endl;
	cout << "--------------------------------------------" << endl;
	cout << "D | " << G( D1 ) << " " << G( D2 ) << " " << G( D3 ) << " " << G( D4 ) << " " << G( D5 ) << " " << G( D6 ) << " " 
		<< G( D7 ) << " " << G( D8 ) << " " << G( D9 ) << " " << G( D10 ) << " " << G( D11 ) << " " << G( D12 ) << " " << G( D13 ) << endl;
	cout << "============================================" << endl;
	cout << endl;
	cout << "============================================" << endl;
	cout << "C | " << G( C1 ) << " " << G( C2 ) << " " << G( C3 ) << " " << G( C4 ) << " " << G( C5 ) << " " << G( C6 ) << " " 
		<< G( C7 ) << " " << G( C8 ) << " " << G( C9 ) << " " << G( C10 ) << " " << G( C11 ) << " " << G( C12 ) << " " << G( C13 ) << endl;
	cout << "--------------------------------------------" << endl;
	cout << "B | " << G( B1 ) << " " << G( B2 ) << " " << G( B3 ) << " " << G( B4 ) << " " << G( B5 ) << " " << G( B6 ) << " " 
		<< G( B7 ) << " " << G( B8 ) << " " << G( B9 ) << " " << G( B10 ) << " " << G( B11 ) << " " << G( B12 ) << " " << G( B13 ) << endl;
	cout << "--------------------------------------------" << endl;
	cout << "A | " << G( A1 ) << " " << G( A2 ) << " " << G( A3 ) << " " << G( A4 ) << " " << G( A5 ) << " " << G( A6 ) << " " 
		<< G( A7 ) << " " << G( A8 ) << " " << G( A9 ) << " " << G( A10 ) << " " << G( A11 ) << " " << G( A12 ) << " " << G( A13 ) << endl;
	cout << "============================================" << endl << endl;
	cout << "���F�\��@�@�~�F�\���" << endl;
	cout << "********************************************" << endl;
}