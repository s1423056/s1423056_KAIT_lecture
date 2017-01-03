// SelectSortArray.h
// 選択法を行う配列を扱うクラス

#ifndef _SELECTSORT_ARRAY_H
#define _SELECTSORT_ARRAY_H

#include "Array.h"

template <class TYPE>
class CSelectSortArray : public CArray <TYPE>
{
private:
	int iMin;		// 最小の要素のインデックス
	TYPE nMin;	// 現在の最小データ

public:
	// コンストラクタ
	CSelectSortArray( const int val );

	// ソート実行
	void Sort();

	// 比較回数と代入回数を測るためのソート
	void CompSort();
};

// ================================
// コンストラクタ
// ================================
template <class TYPE>
CSelectSortArray <TYPE> ::CSelectSortArray( const int val ) : CArray( val )
{
	iMin = 0;
	nMin = 0;
}

// ================================
// 選択法ソート実行
// ================================
template <class TYPE>
void CSelectSortArray <TYPE> ::Sort()
{
	// 要素数-1回ループ
	for( int i = 0; i < m_iArrayNum - 1; i++ ){

		// 初期値代入
		iMin = i;
		nMin = m_Array[i];

		// 最小要素を検索
		for( int j = i + 1; j < m_iArrayNum; j++ ){
			if( m_Array[j] < nMin ){ // より小さい要素が見つかったら
				iMin = j;	// 要素番号を覚えておく
				nMin = m_Array[j]; // 最小データ更新
			}
		}

		// 入れ替え
		Swap( m_Array[iMin], m_Array[i] );

	}
}

// ================================
// 比較回数と代入回数を測るためのソート
// ================================
template <class TYPE>
void CSelectSortArray <TYPE> ::CompSort()
{
	// 要素数-1回ループ
	for( int i = 0; i < m_iArrayNum - 1; i++ ){

		// 初期値代入
		iMin = i;
		nMin = m_Array[i];

		// 最小要素を検索
		for( int j = i + 1; j < m_iArrayNum; j++ ){
			if( m_Array[j] < nMin ){ // より小さい要素が見つかったら
				iMin = j;	// 要素番号を覚えておく
				nMin = m_Array[j]; // 最小データ更新
			}
			compareCount++; // 比較回数＋1
		}

		// 入れ替え
		Swap( m_Array[iMin], m_Array[i] );
		substituteCount++;	// 代入回数＋１
	}
}

#endif