// UI.h
// ���[�U�[�C���^�[�t�F�C�X
// �쐬���F2016/6/7
// �쐬�ҁF�n� ��

#ifndef _UI_H
#define _UI_H

#include "UserInput.h"
#include "Display.h"
#include "Converter.h"

using namespace std;

class CUserInterface
{
private:
	CUserInput input;	// ����
	CDisplay display;		// ��ʕ\���N���X

public:
	// �R���X�g���N�^
	// seatM�F���ȊǗ��N���X�̃|�C���^
	// converter�Fstring��SEAT_NUM�ɕϊ�����N���X�̃|�C���^
	CUserInterface( CSeatManager* seatM, CConverter* converter );

	// ��ʕ\��
	void Display();

	// ���[�U�[����
	UserData Input();

	// ���[�U�[������
	string InputName(){ return input.InputName(); }

	// ���Ȕԍ�����
	string InputSeatNum(){ return input.InputSeatNum(); }

};

#endif