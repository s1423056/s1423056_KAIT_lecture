// Array.h
// さまざまな型の配列を扱うクラス宣言

#ifndef _ARRAY_H
#define _ARRAY_H

#include <iostream>
#include <stdlib.h>

template <class TYPE>
class CArray
{
protected:
	TYPE* m_Array;		// 配列
	int m_iArrayNum;	// 配列の要素数
	int compareCount;	// 比較回数
	int substituteCount;	// 代入回数

private:
	// 初期化
	void Init();

	// 解放
	void Release();

		// インデックスチェック
	void CheckIndex( const int index ) const;

public:
	// コンストラクタ
	explicit CArray( const int num );

	// コピーコンストラクタ
	CArray( const CArray <TYPE> & rother );

	// デストラクタ
	virtual ~CArray();

	// 配列に数値をランダムで入れる初期化
	// val : 配列の要素数
	void Init( const int val );
	
	// ソート実行
	virtual void Sort(){};

	// 比較回数、代入回数を測るためのソート
	virtual void CompSort(){};
	
	// 要素へのアクセス
	TYPE Get( const int index ) const;
	void Set( const int index, const TYPE value );
	
	// メンバの参照
	TYPE& operator []( unsigned int index );
	TYPE& operator []( int index );
	TYPE operator []( unsigned int index ) const;
	TYPE operator []( int index ) const;

	// 配列の直接参照
	operator const TYPE* () const;

	// 配列が有効かどうか
	bool IsValid() const;

	// 配列の要素数を取得
	int ArrayNum() const;

	// 配列のサイズを取得
	int ArraySize() const;

	// 比較回数を取得
	int GetCompareCount() const;

	// 代入回数を取得
	int GetSubstituteCount() const;

	// 配列のコピー
	bool Copy( const CArray <TYPE> & rother );

	// =演算子のオーバーロード
	CArray <TYPE> & operator =( const CArray <TYPE> & rother );

	// 要素の入れ替え
	void Swap( TYPE& val1, TYPE& val2 );

	// 要素を表示
	void Disp();
};


// コンストラクタ
template <class TYPE>
CArray <TYPE> ::CArray( const int num )
{
	compareCount = 0;
	substituteCount = 0;
	m_Array = new TYPE[num];
	if( m_Array == NULL ) 
		m_iArrayNum = 0;
	else
		m_iArrayNum = num;	
}

CArray <int> ::CArray( const int num )
{
	compareCount = 0;
	substituteCount = 0;
	m_Array = new int[num];
	if( m_Array == NULL ) 
		m_iArrayNum = 0;
	else
		m_iArrayNum = num;

	srand( 1423056 );
	for( int i = 0; i < m_iArrayNum; i++)
		m_Array[i] = rand();
}

CArray <float> ::CArray( const int num )
{
	compareCount = 0;
	substituteCount = 0;
	m_Array = new float[num];
	if( m_Array == NULL )
		m_iArrayNum = 0;
	else
		m_iArrayNum = num;

	srand( 1423056 );
	for( int i = 0; i < m_iArrayNum; i++ )
		m_Array[i] = (float)rand() / RAND_MAX;
}

// コピーコンストラクタ
template <class TYPE>
CArray <TYPE> ::CArray( const  CArray <TYPE> & rother )
{
	Init();
	Copy( rother );
}

// デストラクタ
template <class TYPE>
CArray <TYPE> ::~CArray()
{
	Release();
}

// 配列にランダムに数値を入れる初期化
template <>
void CArray <int> ::Init( const int val )
{
	srand( 1423056 );
	for( int i = 0; i < val; i++)
		m_Array[i] = rand();
}

template <>
void CArray <float> ::Init( const int val )
{
	srand( 1423056 );
	for( int i = 0; i < val; i++ )
		m_Array[i] = (float)rand() / RAND_MAX;
}

// メンバの参照
template <class TYPE>
TYPE& CArray <TYPE> ::operator []( unsigned int index )
{
	CheckIndex( index );
	return m_Array[index];
}

template <class TYPE>
inline TYPE& CArray <TYPE> ::operator []( int index )
{
	CheckIndex( index );
	return (*this)[(unsigned int)index];
}

template <class TYPE>
TYPE CArray <TYPE> ::operator []( unsigned int index ) const
{
	CheckIndex( index );
	return m_Array[index];
}

template <class TYPE>
inline TYPE CArray <TYPE> ::operator []( int index ) const
{
	CheckIndex( index );
	return (*this)[(unsigned int)index];
}

// 配列の直接参照
template <class TYPE>
inline CArray <TYPE> ::operator const TYPE*() const
{
	return m_Array;
}

// 要素を取得
template <class TYPE>
TYPE CArray <TYPE> ::Get( const int index ) const
{
	CheckIndex( index );
	return m_Array[index];
}

// 要素に数を代入
template <class TYPE>
void CArray <TYPE> ::Set( const int index, const TYPE value )
{
	CheckIndex( index );
	m_Array[index] = value;
}

// 配列のコピー
template <class TYPE>
bool CArray <TYPE> ::Copy( const CArray& rother )
{
	// 自身はコピーしない
	if( this == &rother )
		return true;

	Release();	// 配列が確保されているときはメモリ解放
	if( rother.IsValid() == true ){
		m_Array = new TYPE[rother.m_iArrayNum];
		if( m_Array == NULL ){
			m_iArrayNum = 0;
			return false;
		}
		m_iArrayNum = rother.m_iArrayNum;
		for( int i = 0; i < m_iArrayNum; i++)
			m_Array[i] = rother [i];
	}
	return true;
}

// ＝演算子のオーバーロード
template <class TYPE>
CArray <TYPE> & CArray <TYPE> ::operator =( const CArray& rother )
{
	Copy( rother );
	return *this;
}

// インデックスチェック
template <class TYPE>
void CArray <TYPE> ::CheckIndex( const int index ) const
{
	if( (unsigned int)index < (unsigned int)m_iArrayNum )
		return;

	cout << "インデックスが不正です" << endl
			<< "値：" << index << endl;
	exit( 1 );
}

// 配列が有効かどうか
template <class TYPE>
inline bool CArray <TYPE> ::IsValid() const
{
	return m_Array != NULL;
}

// 配列の要素数を取得
template <class TYPE>
inline int CArray <TYPE> ::ArrayNum() const
{
	return m_iArrayNum;
}

// 配列のサイズを取得
template <class TYPE>
inline int CArray <TYPE> ::ArraySize() const
{
	return m_iArrayNum * sizeof *m_Array;
}

// 比較回数を取得
template <class TYPE>
inline int CArray <TYPE> ::GetCompareCount() const
{
	return compareCount;
}

// 代入回数を取得
template <class TYPE>
inline int CArray <TYPE> ::GetSubstituteCount() const
{
	return substituteCount;
}

// 初期化
template <class TYPE>
void CArray <TYPE> ::Init()
{
	m_Array = NULL;
	m_iArrayNum = 0;
	compareCount = 0;
	substituteCount = 0;
}

// 解放
template <class TYPE>
void CArray <TYPE> ::Release()
{
	if( IsValid() == true ){
		delete[] m_Array;
		Init();
	}
};

// 要素の入れ替え
template <class TYPE>
void CArray <TYPE> ::Swap( TYPE& val1, TYPE& val2 )
{
	TYPE temp = val1;
	val1 = val2;
	val2 = temp;
}

// 要素を表示
template <class TYPE>
void CArray <TYPE> ::Disp()
{
	for( int i = 0; i < m_iArrayNum; i++ ){
		cout << i << " : " << m_Array[i] << endl;
	}
}

#endif