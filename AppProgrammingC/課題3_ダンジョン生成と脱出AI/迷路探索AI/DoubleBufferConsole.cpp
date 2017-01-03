// DoubleBufferConsole.cpp
// �R���\�[�����_�u���o�b�t�@�����O�ŕ`�悷��N���X

#include "DoubleBufferConsole.h"

// �R���X�g���N�^
DoubleBufferConsole::DoubleBufferConsole() : m_bSwapped( false )
{
	// �o�b�t�@1�쐬
	m_handle1 = CreateConsoleScreenBuffer(
									GENERIC_READ | GENERIC_WRITE,
									0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL );
	// �o�b�t�@2�쐬
	m_handle2 = CreateConsoleScreenBuffer(
									GENERIC_READ | GENERIC_WRITE,
									0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL );
	// �o�b�t�@1���g�p
	SetConsoleActiveScreenBuffer( m_handle1 );
	CONSOLE_CURSOR_INFO info;
	info.dwSize = 1;
	info.bVisible = FALSE;
	SetConsoleCursorInfo( m_handle1, &info );
	SetConsoleCursorInfo( m_handle2, &info );
}

// �f�X�g���N�^
DoubleBufferConsole::~DoubleBufferConsole()
{
	CloseHandle( m_handle1 );
	CloseHandle( m_handle2 );
}

// �J�[�\���ʒu�ݒ�
void DoubleBufferConsole::SetCursorPos( int x, int y )
{
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition( m_bSwapped ? m_handle1 : m_handle2, pos );
}

// char������`��
void DoubleBufferConsole::Write( const char* p )
{
	DWORD len = strlen( p );
	WriteConsoleA( m_bSwapped ? m_handle1 : m_handle2, p, len, &len, 0 );
}

// ���C�hchar������`��
void DoubleBufferConsole::Write( const wchar_t* p )
{
	DWORD len = wcslen( p );
	WriteConsoleW( m_bSwapped ? m_handle1 : m_handle2, p, len, &len, NULL );
}

// string������`��
void DoubleBufferConsole::Write( const std::string& str )
{
	DWORD len = str.size();
	WriteConsoleA( m_bSwapped ? m_handle1 : m_handle2, str.c_str(), len, &len, NULL );
}

// ���C�hstring������`��
void DoubleBufferConsole::Write( const std::wstring& str )
{
	DWORD len = str.size();
	WriteConsoleA( m_bSwapped ? m_handle1 : m_handle2, str.c_str(), len, &len, NULL );
}

// �o�b�t�@����ւ�
void DoubleBufferConsole::Swap()
{
	if( ( m_bSwapped = !m_bSwapped ) )
		SetConsoleActiveScreenBuffer( m_handle2 );
	else
		SetConsoleActiveScreenBuffer( m_handle1 );
}