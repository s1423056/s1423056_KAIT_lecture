// QuickSortArray.h
// クイックソートを行う配列を扱うクラス

#ifndef _QUICKSORT_ARRAY_H
#define _QUICKSORT_ARRAY_H

#include "Array.h"

template <class TYPE>
class CQuickSortArray : public CArray <TYPE>
{
private:
	// 再帰関数
	void SortSub( const int start, const int end );

	// 比較回数と代入回数を測るための再帰関数
	void CompSortSub( const int start, const int end );

public:
	// コンストラクタ
	CQuickSortArray( const int val );

	// クイックソート実行
	void Sort();

	// 比較回数と代入回数を測るためのソート
	void CompSort();
	
};

// ================================
// コンストラクタ
// ================================
template <class TYPE>
CQuickSortArray <TYPE> ::CQuickSortArray( const int num ) : CArray( num )
{}

// ================================
// クイックソート実行
// ================================
template <class TYPE>
void CQuickSortArray <TYPE> ::Sort()
{
	SortSub( 0, m_iArrayNum - 1 );
}

// ================================
// 比較回数と代入回数を測るためのソート
// ================================
template <class TYPE>
void CQuickSortArray <TYPE> ::CompSort()
{
	CompSortSub( 0, m_iArrayNum - 1 );
}

// ================================
// 再帰関数
// ================================
template <class TYPE>
void CQuickSortArray <TYPE> ::SortSub( const int start, const int end )
{
	if( start >= end ) return;

	int iLess = start;	// 前半のインデックス
	int iGreater = end;	// 後半のインデックス
	TYPE temp = ( m_Array[iLess] + m_Array[iGreater] ) / 2;			// 基準値は両端の平均

	// 交換ループ
	while( iLess < iGreater )
	{
		// tempより小さい要素をスルー
		while( m_Array[iLess] < temp ) iLess++;
		// tempより大きい要素をスルー
		while( m_Array[iGreater] > temp ) iGreater--;

		// 検索位置が交わったら交換し、iLessとiGreaterを進める
		if( iLess < iGreater )
			Swap( m_Array[iLess++], m_Array[iGreater--] );

	}

	// iLess == iGreater で終わった時は
	// iGreater < iLessとなるようにする
	if( iLess == iGreater )
	{
		if( m_Array[iLess] < temp )
			iLess++;
		else if( m_Array[iLess] > temp )
			iGreater--;
	}

	// 次のブロックのサイズが2以上ならば再帰
	if( iLess >= start + 2 )
		SortSub( start, iLess - 1);
	if( iGreater <= end + 2 )
		SortSub( iGreater + 1, end );
}


// ================================
// 比較回数と代入回数を測るための再帰関数
// ================================
template <class TYPE>
void CQuickSortArray <TYPE> ::CompSortSub( const int start, const int end )
{
	if( start >= end ) return;

	int iLess = start;	// 前半のインデックス
	int iGreater = end;	// 後半のインデックス
	TYPE temp = ( m_Array[iLess] + m_Array[iGreater] ) / 2;			// 基準値は両端の平均

	// 交換ループ
	while( iLess < iGreater )
	{
		// tempより小さい要素をスルー
		while( m_Array[iLess] < temp ){
			iLess++;
			compareCount++;
		}
		// tempより大きい要素をスルー
		while( m_Array[iGreater] > temp ){
			iGreater--;
			compareCount++;
		}
		// 検索位置が交わったら交換し、iLessとiGreaterを進める
		if( iLess < iGreater ){
			Swap( m_Array[iLess++], m_Array[iGreater--] );
			substituteCount++; // 代入回数＋1
		}
	}

	// iLess == iGreater で終わった時は
	// iGreater < iLessとなるようにする
	if( iLess == iGreater )
	{
		if( m_Array[iLess] < temp )
			iLess++;
		else if( m_Array[iLess] > temp )
			iGreater--;
	}

	// 次のブロックのサイズが2以上ならば再帰
	if( iLess >= start + 2 )
		SortSub( start, iLess - 1);
	if( iGreater <= end + 2 )
		SortSub( iGreater + 1, end );
}


#endif