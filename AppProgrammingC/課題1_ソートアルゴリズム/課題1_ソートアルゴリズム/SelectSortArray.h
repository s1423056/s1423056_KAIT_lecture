// SelectSortArray.h
// �I��@���s���z��������N���X

#ifndef _SELECTSORT_ARRAY_H
#define _SELECTSORT_ARRAY_H

#include "Array.h"

template <class TYPE>
class CSelectSortArray : public CArray <TYPE>
{
private:
	int iMin;		// �ŏ��̗v�f�̃C���f�b�N�X
	TYPE nMin;	// ���݂̍ŏ��f�[�^

public:
	// �R���X�g���N�^
	CSelectSortArray( const int val );

	// �\�[�g���s
	void Sort();

	// ��r�񐔂Ƒ���񐔂𑪂邽�߂̃\�[�g
	void CompSort();
};

// ================================
// �R���X�g���N�^
// ================================
template <class TYPE>
CSelectSortArray <TYPE> ::CSelectSortArray( const int val ) : CArray( val )
{
	iMin = 0;
	nMin = 0;
}

// ================================
// �I��@�\�[�g���s
// ================================
template <class TYPE>
void CSelectSortArray <TYPE> ::Sort()
{
	// �v�f��-1�񃋁[�v
	for( int i = 0; i < m_iArrayNum - 1; i++ ){

		// �����l���
		iMin = i;
		nMin = m_Array[i];

		// �ŏ��v�f������
		for( int j = i + 1; j < m_iArrayNum; j++ ){
			if( m_Array[j] < nMin ){ // ��菬�����v�f������������
				iMin = j;	// �v�f�ԍ����o���Ă���
				nMin = m_Array[j]; // �ŏ��f�[�^�X�V
			}
		}

		// ����ւ�
		Swap( m_Array[iMin], m_Array[i] );

	}
}

// ================================
// ��r�񐔂Ƒ���񐔂𑪂邽�߂̃\�[�g
// ================================
template <class TYPE>
void CSelectSortArray <TYPE> ::CompSort()
{
	// �v�f��-1�񃋁[�v
	for( int i = 0; i < m_iArrayNum - 1; i++ ){

		// �����l���
		iMin = i;
		nMin = m_Array[i];

		// �ŏ��v�f������
		for( int j = i + 1; j < m_iArrayNum; j++ ){
			if( m_Array[j] < nMin ){ // ��菬�����v�f������������
				iMin = j;	// �v�f�ԍ����o���Ă���
				nMin = m_Array[j]; // �ŏ��f�[�^�X�V
			}
			compareCount++; // ��r�񐔁{1
		}

		// ����ւ�
		Swap( m_Array[iMin], m_Array[i] );
		substituteCount++;	// ����񐔁{�P
	}
}

#endif