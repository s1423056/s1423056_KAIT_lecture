// BubbleSortArray.h
// �o�u���\�[�g�����s����z��������N���X

#ifndef _BUBBLESORT_ARRAY_H
#define _BUBBLESORT_ARRAY_H

#include "Array.h"

template <class TYPE>
class CBubbleSortArray : public CArray <TYPE>
{
public:
	// �R���X�g���N�^
	CBubbleSortArray( const int num );

	// �o�u���\�[�g���s
	void Sort();

	// ��r�񐔁A����񐔂𑪂邽�߂̃\�[�g
	void CompSort();
};

// ================================
// �R���X�g���N�^
// ================================
template <class TYPE>
CBubbleSortArray <TYPE> ::CBubbleSortArray( const int val ) : CArray( val )
{}

// ================================
// �o�u���\�[�g���s
// ================================
template <class TYPE>
void CBubbleSortArray <TYPE> ::Sort()
{
	for( int i = 0; i < m_iArrayNum - 1; i++ ){
		for( int j = m_iArrayNum - 1; j > 0; j-- ){ // �����珇�Ɍ���
			if( m_Array[j] < m_Array[j - 1] ) // �P�O�̂ق����傫�����
				Swap( m_Array[j], m_Array[j - 1] );	// ����ւ�
		}
	}
}

template <class TYPE>
void CBubbleSortArray <TYPE> ::CompSort()
{
	for( int i = 0; i < m_iArrayNum - 1; i++ ){
		for( int j = m_iArrayNum - 1; j > 0; j-- ){ // �����珇�Ɍ���
			if( m_Array[j] < m_Array[j - 1] ){ // �P�O�̂ق����傫�����
				Swap( m_Array[j], m_Array[j - 1] );	// ����ւ�
				substituteCount++; // ����񐔁{1
			}
			compareCount++; // ��r�񐔁{1
		}
	}
}

#endif