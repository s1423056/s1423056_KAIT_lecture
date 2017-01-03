// UI.cpp
// ���[�U�[�C���^�[�t�F�C�X
// �쐬���F2016/6/7
// �쐬�ҁF�n� ��

#include "UI.h"
#include <iostream>
using namespace std;

// �R���X�g���N�^
CUserInterface::CUserInterface( CSeatManager* seatM, CConverter* converter )
	: display( seatM ), input( seatM, &display, converter )
{}

// ��ʕ\��
void CUserInterface::Display()
{
	display.Display();
}

// ���[�U�[����
UserData CUserInterface::Input()
{
	UserData data = input.Input();
	return data;
}