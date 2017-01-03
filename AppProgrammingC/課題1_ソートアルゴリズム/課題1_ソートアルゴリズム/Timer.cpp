// Timer.cpp
// 時間計測を行うクラス

#include "Timer.h"
#include <iostream>
using namespace std;

// コンストラクタ
CTimer::CTimer()
{
	// 変数を初期化
	memset( &m_freq, 0x00, sizeof( LARGE_INTEGER ) );
	memset( &m_before, 0x00, sizeof( LARGE_INTEGER ) );
	memset( &m_after, 0x00, sizeof( LARGE_INTEGER ) );
	m_time = 0;
	m_count = 0;

	// CPUの周波数を取得
	QueryPerformanceFrequency( &m_freq );
}

// コンソールに表示
void CTimer::Disp(){
	cout << "================================" << endl;
	cout << "経過時間" << endl;
	cout << "================================" << endl;
	cout << m_count << "カウント" << endl;
	cout << m_time << "ミリ秒" << endl;
}