// Timer.cpp
// ���Ԍv�����s���N���X

#include "Timer.h"
#include <iostream>
using namespace std;

// �R���X�g���N�^
CTimer::CTimer()
{
	// �ϐ���������
	memset( &m_freq, 0x00, sizeof( LARGE_INTEGER ) );
	memset( &m_before, 0x00, sizeof( LARGE_INTEGER ) );
	memset( &m_after, 0x00, sizeof( LARGE_INTEGER ) );
	m_time = 0;
	m_count = 0;

	// CPU�̎��g�����擾
	QueryPerformanceFrequency( &m_freq );
}

// �R���\�[���ɕ\��
void CTimer::Disp(){
	cout << "================================" << endl;
	cout << "�o�ߎ���" << endl;
	cout << "================================" << endl;
	cout << m_count << "�J�E���g" << endl;
	cout << m_time << "�~���b" << endl;
}