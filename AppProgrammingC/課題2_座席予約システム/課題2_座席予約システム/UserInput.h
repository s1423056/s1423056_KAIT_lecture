// UserInput.h
// ���[�U�[����̓��͂��Ǘ�����N���X
// �쐬���F2016/6/8
// �쐬�ҁF�n� ��

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
	string name;						// ���O
	unsigned int num;				// �\�񂵂����Ȑ�
	list<string> seatList;			// �\�񂵂����Ȕԍ��̃��X�g
};

class CUserInput
{
private:
	CSeatManager* seatManager;	// ���ȊǗ��N���X�̃|�C���^
	CDisplay* display;				// ��ʕ\���N���X�̃|�C���^
	CConverter* converter;		// string����SEAT_NUM�֕ϊ�����N���X�̃|�C���^
	
	// ���Ȑ�����
	// ���͂��ꂽ���l��Ԃ�
	int InputNum();

	// ���Ȕԍ�����
	// seatStr�F�m�F�̂��߂ɍ��Ȕԍ����i�[���镶����̃|�C���^
	SEAT_NUM InputSeatNum( string* seatStr );	
	
	// ���͂܂Ƃ�
	// data�F���̓f�[�^�̃|�C���^
	void InputDataSet( UserData* data );

public:
	// �R���X�g���N�^
	// seatM�F���ȊǗ��N���X�̃|�C���^
	CUserInput( CSeatManager* seatM, CDisplay* disp, CConverter* converter );

	// �O������Ăяo�����[�U�[���͊֐�
	UserData Input();
	
	// ���O����
	// ���͂��ꂽ�������Ԃ�
	string InputName();

	// ���Ȕԍ����́i�����j
	string InputSeatNum();
};

#endif