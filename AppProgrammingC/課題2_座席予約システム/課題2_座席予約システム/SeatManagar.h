// SeatManager.h
// ���Ȃ��Ǘ�����N���X
// �쐬���F2016/5/19
// �쐬�ҁF�n� ��

#ifndef _SEATMANAGER_H
#define _SEATMANAGER_H

#include "Seat.h"
#include <iostream>
using namespace std;

class CSeatManager
{
private:
	CSeat seat[65];					// ���Ȃ̔z��
	unsigned int m_iVacancy;	// ��Ȃ̐�
	bool m_bUpdate;					// �X�V���ꂽ���ǂ����̃t���O

public:
	// �R���X�g���N�^
	CSeatManager();

	// ���ȗ\��
	// num�F���Ȕԍ�
	// ���������ꍇtrue�A���s�����ꍇfalse��Ԃ�
	bool Reserve( SEAT_NUM num ){ return seat[num].Reserve(); m_iVacancy--; }

	// �\��L�����Z��
	// num�F���Ȕԍ�
	// ���������ꍇtrue�A���s�����ꍇfalse��Ԃ�
	bool Cansel( SEAT_NUM num ){ return seat[num].Cansel(); m_iVacancy++; }

	// �\��󋵊m�F
	// num�F���Ȕԍ�
	// ���Ȃ��\�񂳂�Ă����true�A����ĂȂ����false��Ԃ�
	bool GetSeatStatus( SEAT_NUM num ) { return seat[num].GetReserved(); }

	// ��Ȃ̐����擾
	unsigned int GetVacancyNum(){ return m_iVacancy; }

	// �X�V���ꂽ���ǂ����̃t���O���擾
	bool GetUpdate(){ return m_bUpdate; }

	// �X�V�t���O���Z�b�g
	// b�F�X�V����true�A�X�V���I������false���Z�b�g����ׂ�
	bool SetUpdate( bool b ){ m_bUpdate = b; }
};

#endif