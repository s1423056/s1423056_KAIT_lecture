// DoubleBufferConsole.h
// コンソールをダブルバッファリングで描画するクラス

#ifndef _DOUBLEBUFFERCONSOLE_H
#define _DOUBLEBUFFERCONSOLR_H

#include <Windows.h>
#include <string>

class DoubleBufferConsole
{
private:
	bool m_bSwapped;		// スワップしたかどうか
	HANDLE m_handle1;	// コンソールハンドル1
	HANDLE m_handle2;	// コンソールハンドル2

public:
	// コンストラクタ
	DoubleBufferConsole();

	// デストラクタ
	~DoubleBufferConsole();

	// カーソル位置設定
	void SetCursorPos( int, int );

	// char文字列描画
	void Write( const char* );

	// ワイドchar文字列描画
	void Write( const wchar_t* );

	// string文字列描画
	void Write( const std::string& );

	// ワイドstring文字列描画
	void Write( const std::wstring& );

	// バッファ入れ替え
	void Swap();
};

#endif