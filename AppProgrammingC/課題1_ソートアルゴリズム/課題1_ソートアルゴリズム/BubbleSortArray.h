// BubbleSortArray.h
// バブルソートを実行する配列を扱うクラス

#ifndef _BUBBLESORT_ARRAY_H
#define _BUBBLESORT_ARRAY_H

#include "Array.h"

template <class TYPE>
class CBubbleSortArray : public CArray <TYPE>
{
public:
	// コンストラクタ
	CBubbleSortArray( const int num );

	// バブルソート実行
	void Sort();

	// 比較回数、代入回数を測るためのソート
	void CompSort();
};

// ================================
// コンストラクタ
// ================================
template <class TYPE>
CBubbleSortArray <TYPE> ::CBubbleSortArray( const int val ) : CArray( val )
{}

// ================================
// バブルソート実行
// ================================
template <class TYPE>
void CBubbleSortArray <TYPE> ::Sort()
{
	for( int i = 0; i < m_iArrayNum - 1; i++ ){
		for( int j = m_iArrayNum - 1; j > 0; j-- ){ // 下から順に検索
			if( m_Array[j] < m_Array[j - 1] ) // １つ前のほうが大きければ
				Swap( m_Array[j], m_Array[j - 1] );	// 入れ替え
		}
	}
}

template <class TYPE>
void CBubbleSortArray <TYPE> ::CompSort()
{
	for( int i = 0; i < m_iArrayNum - 1; i++ ){
		for( int j = m_iArrayNum - 1; j > 0; j-- ){ // 下から順に検索
			if( m_Array[j] < m_Array[j - 1] ){ // １つ前のほうが大きければ
				Swap( m_Array[j], m_Array[j - 1] );	// 入れ替え
				substituteCount++; // 代入回数＋1
			}
			compareCount++; // 比較回数＋1
		}
	}
}

#endif