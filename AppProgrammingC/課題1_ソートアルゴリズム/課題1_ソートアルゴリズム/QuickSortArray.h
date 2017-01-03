// QuickSortArray.h
// �N�C�b�N�\�[�g���s���z��������N���X

#ifndef _QUICKSORT_ARRAY_H
#define _QUICKSORT_ARRAY_H

#include "Array.h"

template <class TYPE>
class CQuickSortArray : public CArray <TYPE>
{
private:
	// �ċA�֐�
	void SortSub( const int start, const int end );

	// ��r�񐔂Ƒ���񐔂𑪂邽�߂̍ċA�֐�
	void CompSortSub( const int start, const int end );

public:
	// �R���X�g���N�^
	CQuickSortArray( const int val );

	// �N�C�b�N�\�[�g���s
	void Sort();

	// ��r�񐔂Ƒ���񐔂𑪂邽�߂̃\�[�g
	void CompSort();
	
};

// ================================
// �R���X�g���N�^
// ================================
template <class TYPE>
CQuickSortArray <TYPE> ::CQuickSortArray( const int num ) : CArray( num )
{}

// ================================
// �N�C�b�N�\�[�g���s
// ================================
template <class TYPE>
void CQuickSortArray <TYPE> ::Sort()
{
	SortSub( 0, m_iArrayNum - 1 );
}

// ================================
// ��r�񐔂Ƒ���񐔂𑪂邽�߂̃\�[�g
// ================================
template <class TYPE>
void CQuickSortArray <TYPE> ::CompSort()
{
	CompSortSub( 0, m_iArrayNum - 1 );
}

// ================================
// �ċA�֐�
// ================================
template <class TYPE>
void CQuickSortArray <TYPE> ::SortSub( const int start, const int end )
{
	if( start >= end ) return;

	int iLess = start;	// �O���̃C���f�b�N�X
	int iGreater = end;	// �㔼�̃C���f�b�N�X
	TYPE temp = ( m_Array[iLess] + m_Array[iGreater] ) / 2;			// ��l�͗��[�̕���

	// �������[�v
	while( iLess < iGreater )
	{
		// temp��菬�����v�f���X���[
		while( m_Array[iLess] < temp ) iLess++;
		// temp���傫���v�f���X���[
		while( m_Array[iGreater] > temp ) iGreater--;

		// �����ʒu�����������������AiLess��iGreater��i�߂�
		if( iLess < iGreater )
			Swap( m_Array[iLess++], m_Array[iGreater--] );

	}

	// iLess == iGreater �ŏI���������
	// iGreater < iLess�ƂȂ�悤�ɂ���
	if( iLess == iGreater )
	{
		if( m_Array[iLess] < temp )
			iLess++;
		else if( m_Array[iLess] > temp )
			iGreater--;
	}

	// ���̃u���b�N�̃T�C�Y��2�ȏ�Ȃ�΍ċA
	if( iLess >= start + 2 )
		SortSub( start, iLess - 1);
	if( iGreater <= end + 2 )
		SortSub( iGreater + 1, end );
}


// ================================
// ��r�񐔂Ƒ���񐔂𑪂邽�߂̍ċA�֐�
// ================================
template <class TYPE>
void CQuickSortArray <TYPE> ::CompSortSub( const int start, const int end )
{
	if( start >= end ) return;

	int iLess = start;	// �O���̃C���f�b�N�X
	int iGreater = end;	// �㔼�̃C���f�b�N�X
	TYPE temp = ( m_Array[iLess] + m_Array[iGreater] ) / 2;			// ��l�͗��[�̕���

	// �������[�v
	while( iLess < iGreater )
	{
		// temp��菬�����v�f���X���[
		while( m_Array[iLess] < temp ){
			iLess++;
			compareCount++;
		}
		// temp���傫���v�f���X���[
		while( m_Array[iGreater] > temp ){
			iGreater--;
			compareCount++;
		}
		// �����ʒu�����������������AiLess��iGreater��i�߂�
		if( iLess < iGreater ){
			Swap( m_Array[iLess++], m_Array[iGreater--] );
			substituteCount++; // ����񐔁{1
		}
	}

	// iLess == iGreater �ŏI���������
	// iGreater < iLess�ƂȂ�悤�ɂ���
	if( iLess == iGreater )
	{
		if( m_Array[iLess] < temp )
			iLess++;
		else if( m_Array[iLess] > temp )
			iGreater--;
	}

	// ���̃u���b�N�̃T�C�Y��2�ȏ�Ȃ�΍ċA
	if( iLess >= start + 2 )
		SortSub( start, iLess - 1);
	if( iGreater <= end + 2 )
		SortSub( iGreater + 1, end );
}


#endif