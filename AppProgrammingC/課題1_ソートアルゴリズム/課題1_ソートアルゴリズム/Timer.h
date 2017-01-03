// Timer.h
// 時間計測を行うクラス

#ifndef _TIMER_H
#define _TIMER_H

#include <Windows.h>
#include <stdlib.h>

class CTimer{
private:
	LARGE_INTEGER m_freq;		// 周波数
	LARGE_INTEGER m_before;	// 計測開始時刻
	LARGE_INTEGER m_after;		// 計測終了時刻
	LONGLONG m_time;						// 結果(ミリ秒単位)
	LONGLONG m_count;				// 結果(カウント数)

public:
	// コンストラクタ
	CTimer();

	// 計測開始
	void Begin(){ QueryPerformanceCounter( &m_before ); }

	// 計測終了
	void End(){
		QueryPerformanceCounter( &m_after );

		// 経過時間を計算
		m_count = ( m_after.QuadPart - m_before.QuadPart );
		m_time = m_count * 1000 / m_freq.QuadPart ;
	}

	// カウント数取得
	LONGLONG GetCount(){ return m_count; }

	// 時間結果取得
	LONGLONG GetTime(){ return m_time; }

	// コンソールに表示
	void Disp();
};

#endif