// SeatManager.cpp
// ���Ȃ��Ǘ�����N���X
// �쐬���F2016/5/19
// �쐬�ҁF�n� ��

#include "SeatManagar.h"

// �R���X�g���N�^
CSeatManager::CSeatManager()
{
	// ���l�̏�����
	for( int i = A1; i < NONE; i++ ){
		seat[i].Initialize( (SEAT_NUM)i, false );
	}
	m_iVacancy = NONE;
}