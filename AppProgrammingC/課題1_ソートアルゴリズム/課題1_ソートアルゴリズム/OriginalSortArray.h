// OriginalSort.h
// オリジナルのソートを行う配列を扱うクラス

#ifndef _ORIGINALSORT_ARRAY_H
#define _ORIGINALSORT_ARRAY_H

#include "Array.h"

template <class TYPE>
class COriginalSortArray : public CArray <TYPE>
{
private:
	int iMin, iMax;			// 最小の要素のインデックス
	TYPE nMin, nMax;	// 現在の最小のデータ

public:
	// コンストラクタ
	COriginalSortArray( const int val );

	// ソート実行
	void Sort();

	// 比較回数と代入回数を測るためのソート
	void CompSort();
};

// ================================
// コンストラクタ
// ================================
template <class TYPE>
COriginalSortArray <TYPE> ::COriginalSortArray( const int val ) : CArray( val )
{
	iMin = 0;
	nMin = 0;
	iMax = 0;
	nMax = 0;
}

// ================================
// ソート実行
// ================================
template <class TYPE>
void COriginalSortArray <TYPE> ::Sort()
{
	int h = m_iArrayNum - 1; // 一番後ろの要素のインデックス
	// 要素数 - 1 回ループ
	for( int i = 0; i < h; i++ ){

		// 初期値代入
		iMin = iMax = i;
		nMin = m_Array[i];
		nMax = m_Array[h];

		// 最小要素と最大要素を検索
		for( int j = i + 1; j < h; j++ ){
			if( m_Array[j] < nMin ){	// より小さい要素が見つかったら
				iMin = j;
				nMin = m_Array[j];
			}
			else if( m_Array[j] > nMax ){ // より大きい要素が見つかったら
				iMax = j;
				nMax = m_Array[j];
			}
		}

		// 入れ替え
		Swap( m_Array[iMin], m_Array[i] );
		Swap( m_Array[iMax], m_Array[h] );

		h--;
	}
}

// ================================
// 比較回数と代入回数を測るためのソート
// ================================
template <class TYPE>
void COriginalSortArray <TYPE> ::CompSort()
{
	int h = m_iArrayNum - 1; // 一番後ろの要素のインデックス
	// 要素数 - 1 回ループ
	for( int i = 0; i < h; i++ ){

		// 初期値代入
		iMin = iMax = i;
		nMin = m_Array[i];
		nMax = m_Array[h];

		// 最小要素と最大要素を検索
		for( int j = i + 1; j < h; j++ ){
			if( m_Array[j] < nMin ){	// より小さい要素が見つかったら
				iMin = j;
				nMin = m_Array[j];
				compareCount++; // 比較回数＋1
			}
			else if( m_Array[j] > nMax ){ // より大きい要素が見つかったら
				iMax = j;
				nMax = m_Array[j];
				compareCount++; // 比較回数＋１
			}
		}

		// 入れ替え
		Swap( m_Array[iMin], m_Array[i] ); substituteCount++; // 代入回数＋1
		Swap( m_Array[iMax], m_Array[h] ); substituteCount++; // 代入回数＋1

		h--;
	}
}

#endif