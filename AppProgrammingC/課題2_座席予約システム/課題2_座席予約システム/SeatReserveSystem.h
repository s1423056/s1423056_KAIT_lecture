// SeatReserveSystem.h
// ���ȗ\��Ǘ��V�X�e���̃N���X
// �쐬���F2016/6/7
// �쐬�ҁF�n� ��

#ifndef _SEATRESERVESYSTEM_H
#define _SEATRESERVESYSTEM_H

#include "SeatManagar.h"
#include "FileManager.h"
#include "UI.h"

class CSeatReserveSystem{
private:
	CSeatManager seatManager;	// ���ȊǗ�
	CFileManager fileManager;		// �t�@�C�����o�͊Ǘ�
	CUserInterface UI;					// ���[�U�[����
	CConverter converter;				// string��SEAT_NUM�ɕϊ�����N���X

	// �\����s
	void Reserve();

	// �L�����Z�����s
	void Cansel();
		
	// �t�@�C����ǂݍ���ŏ�Ԃ��X�V
	void Update();

public:
	// �R���X�g���N�^
	CSeatReserveSystem();

	// ���s
	void Run();
	

};

#endif