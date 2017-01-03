// DoubleBufferConsole.h
// �R���\�[�����_�u���o�b�t�@�����O�ŕ`�悷��N���X

#ifndef _DOUBLEBUFFERCONSOLE_H
#define _DOUBLEBUFFERCONSOLR_H

#include <Windows.h>
#include <string>

class DoubleBufferConsole
{
private:
	bool m_bSwapped;		// �X���b�v�������ǂ���
	HANDLE m_handle1;	// �R���\�[���n���h��1
	HANDLE m_handle2;	// �R���\�[���n���h��2

public:
	// �R���X�g���N�^
	DoubleBufferConsole();

	// �f�X�g���N�^
	~DoubleBufferConsole();

	// �J�[�\���ʒu�ݒ�
	void SetCursorPos( int, int );

	// char������`��
	void Write( const char* );

	// ���C�hchar������`��
	void Write( const wchar_t* );

	// string������`��
	void Write( const std::string& );

	// ���C�hstring������`��
	void Write( const std::wstring& );

	// �o�b�t�@����ւ�
	void Swap();
};

#endif