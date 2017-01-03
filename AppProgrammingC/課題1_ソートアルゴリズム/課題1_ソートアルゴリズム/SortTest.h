// SortTest.h
// ソート検証を行うクラス

#ifndef _SORTTEST_H
#define _SORTTEST_H

#include "Array.h"
#include "Timer.h"
#include <fstream>

class CSortTest
{
private:
	CTimer timer;			// タイマー
	LONGLONG count;	// 平均カウント数
	LONGLONG time;		// 平均時間
	LONGLONG minCount, maxCount;	// 最大カウント数、最小カウント数
	LONGLONG minTime, maxTime;		// 最大時間、最小時間

	// テスト実行
	// ary：ソートを行う配列
	// arrayNum：配列の要素数
	// testNum：試行回数
	template <class TYPE>
	void Test( CArray<TYPE>* ary, const int arrayNum, const int testNum )
	{
		ary -> CompSort();	// 比較回数と代入回数を計測

		for( int i = 0; i < testNum; i++ ){
			ary -> Init( arrayNum );	// 配列初期化

			timer.Begin();		// 計測開始
			ary -> Sort();		// ソート実行
			timer.End();			// 計測終了

			// このあと何度もtimerの変数を使うので一時変数に保存しておく
			LONGLONG tCount = timer.GetCount();
			LONGLONG tTime = timer.GetTime();

			if( i == 0 ){
				// 1回目の結果を最大・最小の値として保存しておく
				maxCount = minCount = tCount;
				maxTime = minTime = tTime;
			}else{
				// 2回目以降は最大か最小かを検証して、変数を更新
				if( maxCount < tCount ) maxCount = tCount;
				else if( minCount > tCount ) minCount = tCount;
				if( maxTime < tTime ) maxTime = tTime;
				else if( minTime > tTime ) minTime = tTime;
			}

			count += tCount;	// カウント数を加算
			time += tTime;		// 時間を加算

			/*
			// コンソール表示
			cout << "============" << i << "回目" << "============" << endl;
			cout << "時間："	<< tTime << "ミリ秒" << endl;
			cout << "CPUカウント数：" << tCount << "カウント" << endl;
			cout << endl;
			*/
		}

		count /= testNum;		// 平均カウント数を計算
		time /= testNum;		// 平均時間を計算

		// 結果表示
		cout << "============結果============" << endl;
		cout << arrayNum << "個の要素数で" << testNum << "回試行しました。" << endl;
		cout << "平均時間：" << time << "ミリ秒" << endl;
		cout << "平均カウント数：" << count << "カウント" << endl;
		cout << "比較回数：" << ary -> GetCompareCount() << "回" << endl;
		cout << "代入回数：" << ary -> GetSubstituteCount() << "回" << endl;
		cout << "--------------------------------" << endl;
		cout << "最大時間：" << maxTime << "ミリ秒" << endl;
		cout << "最小時間：" << minTime << "ミリ秒" << endl;
		cout << "最大カウント数：" << maxCount << "カウント" << endl;
		cout << "最小カウント数：" << minCount << "カウント" << endl << endl;
	}

public:
	// コンストラクタ
	CSortTest(){
		// 変数を0で初期化
		time = 0; count = 0; 
		minCount = 0; maxCount = 0;
		minTime = 0; maxTime = 0;
	}

	// 平均カウント数取得
	LONGLONG GetCount(){ return count; }

	// 平均時間取得
	LONGLONG GetTime(){ return time; }


	// main関数で呼び出す関数
	// ここで試行回数を100回に固定

	// バブルソート
	template <class TYPE>
	void BubbleSortTest( const int arrayNum )
	{	
		// ソートを行う配列クラスを宣言
		CArray<TYPE>* ary = new CBubbleSortArray<TYPE>( arrayNum );
		Test( ary, arrayNum, 100 );	// テスト実行
		delete[] ary; // 後片付け
	}

	// 選択法ソート
	template <class TYPE>
	void SelectSortTest( const int arrayNum )
	{
		// ソートを行う配列クラスを宣言
		CArray<TYPE>* ary = new CSelectSortArray<TYPE>( arrayNum );
		Test( ary, arrayNum, 100 );	// テスト実行
		delete[] ary; // 後片付け
	}

	// クイックソート
	template <class TYPE>
	void QuickSortTest( const int arrayNum )
	{
		// ソートを行う配列クラスを宣言
		CArray<TYPE>* ary = new CQuickSortArray<TYPE>( arrayNum );
		Test( ary, arrayNum, 100 );	// テスト実行
		delete[] ary; // 後片付け
	}

	// オリジナルソート
	template <class TYPE>
	void OriginalSortTest( const int arrayNum )
	{
		// ソートを行う配列クラスを宣言
		CArray<TYPE>* ary = new COriginalSortArray<TYPE>( arrayNum );
		Test( ary, arrayNum, 100 );	// テスト実行
		delete[] ary; // 後片付け
	}
};

#endif