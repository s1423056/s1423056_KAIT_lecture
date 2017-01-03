// Timer.h
// ���Ԍv�����s���N���X

#ifndef _TIMER_H
#define _TIMER_H

#include <Windows.h>
#include <stdlib.h>

class CTimer{
private:
	LARGE_INTEGER m_freq;		// ���g��
	LARGE_INTEGER m_before;	// �v���J�n����
	LARGE_INTEGER m_after;		// �v���I������
	LONGLONG m_time;						// ����(�~���b�P��)
	LONGLONG m_count;				// ����(�J�E���g��)

public:
	// �R���X�g���N�^
	CTimer();

	// �v���J�n
	void Begin(){ QueryPerformanceCounter( &m_before ); }

	// �v���I��
	void End(){
		QueryPerformanceCounter( &m_after );

		// �o�ߎ��Ԃ��v�Z
		m_count = ( m_after.QuadPart - m_before.QuadPart );
		m_time = m_count * 1000 / m_freq.QuadPart ;
	}

	// �J�E���g���擾
	LONGLONG GetCount(){ return m_count; }

	// ���Ԍ��ʎ擾
	LONGLONG GetTime(){ return m_time; }

	// �R���\�[���ɕ\��
	void Disp();
};

#endif