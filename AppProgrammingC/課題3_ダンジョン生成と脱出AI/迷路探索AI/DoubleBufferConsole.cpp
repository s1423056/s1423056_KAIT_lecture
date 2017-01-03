// DoubleBufferConsole.cpp
// コンソールをダブルバッファリングで描画するクラス

#include "DoubleBufferConsole.h"

// コンストラクタ
DoubleBufferConsole::DoubleBufferConsole() : m_bSwapped( false )
{
	// バッファ1作成
	m_handle1 = CreateConsoleScreenBuffer(
									GENERIC_READ | GENERIC_WRITE,
									0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL );
	// バッファ2作成
	m_handle2 = CreateConsoleScreenBuffer(
									GENERIC_READ | GENERIC_WRITE,
									0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL );
	// バッファ1を使用
	SetConsoleActiveScreenBuffer( m_handle1 );
	CONSOLE_CURSOR_INFO info;
	info.dwSize = 1;
	info.bVisible = FALSE;
	SetConsoleCursorInfo( m_handle1, &info );
	SetConsoleCursorInfo( m_handle2, &info );
}

// デストラクタ
DoubleBufferConsole::~DoubleBufferConsole()
{
	CloseHandle( m_handle1 );
	CloseHandle( m_handle2 );
}

// カーソル位置設定
void DoubleBufferConsole::SetCursorPos( int x, int y )
{
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition( m_bSwapped ? m_handle1 : m_handle2, pos );
}

// char文字列描画
void DoubleBufferConsole::Write( const char* p )
{
	DWORD len = strlen( p );
	WriteConsoleA( m_bSwapped ? m_handle1 : m_handle2, p, len, &len, 0 );
}

// ワイドchar文字列描画
void DoubleBufferConsole::Write( const wchar_t* p )
{
	DWORD len = wcslen( p );
	WriteConsoleW( m_bSwapped ? m_handle1 : m_handle2, p, len, &len, NULL );
}

// string文字列描画
void DoubleBufferConsole::Write( const std::string& str )
{
	DWORD len = str.size();
	WriteConsoleA( m_bSwapped ? m_handle1 : m_handle2, str.c_str(), len, &len, NULL );
}

// ワイドstring文字列描画
void DoubleBufferConsole::Write( const std::wstring& str )
{
	DWORD len = str.size();
	WriteConsoleA( m_bSwapped ? m_handle1 : m_handle2, str.c_str(), len, &len, NULL );
}

// バッファ入れ替え
void DoubleBufferConsole::Swap()
{
	if( ( m_bSwapped = !m_bSwapped ) )
		SetConsoleActiveScreenBuffer( m_handle2 );
	else
		SetConsoleActiveScreenBuffer( m_handle1 );
}