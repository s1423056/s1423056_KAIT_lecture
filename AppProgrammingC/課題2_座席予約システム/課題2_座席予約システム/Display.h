// Display.h
// ��ʂ̕\�����s���N���X

#ifndef _DISPLAY_H
#define _DISPLAY_H

#include "SeatManagar.h"
#include <string>
using namespace std;

class CDisplay
{
private:
	CSeatManager* seatManager;// ���ȊǗ��I�u�W�F�N�g�̃|�C���^

	// �\��󋵎擾�𕶎��ɕϊ�����֐�
	string G( SEAT_NUM num ){
		if( seatManager -> GetSeatStatus( num ) )
			return "�~";
		else
			return "��";
	}

public:
	// �R���X�g���N�^
	CDisplay( CSeatManager* seatM ) : seatManager( seatM ){};

	// �\��󋵕\��
	void Display();
};

#endif