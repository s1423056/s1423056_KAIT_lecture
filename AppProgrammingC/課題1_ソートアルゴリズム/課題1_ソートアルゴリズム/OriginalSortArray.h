// OriginalSort.h
// �I���W�i���̃\�[�g���s���z��������N���X

#ifndef _ORIGINALSORT_ARRAY_H
#define _ORIGINALSORT_ARRAY_H

#include "Array.h"

template <class TYPE>
class COriginalSortArray : public CArray <TYPE>
{
private:
	int iMin, iMax;			// �ŏ��̗v�f�̃C���f�b�N�X
	TYPE nMin, nMax;	// ���݂̍ŏ��̃f�[�^

public:
	// �R���X�g���N�^
	COriginalSortArray( const int val );

	// �\�[�g���s
	void Sort();

	// ��r�񐔂Ƒ���񐔂𑪂邽�߂̃\�[�g
	void CompSort();
};

// ================================
// �R���X�g���N�^
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
// �\�[�g���s
// ================================
template <class TYPE>
void COriginalSortArray <TYPE> ::Sort()
{
	int h = m_iArrayNum - 1; // ��Ԍ��̗v�f�̃C���f�b�N�X
	// �v�f�� - 1 �񃋁[�v
	for( int i = 0; i < h; i++ ){

		// �����l���
		iMin = iMax = i;
		nMin = m_Array[i];
		nMax = m_Array[h];

		// �ŏ��v�f�ƍő�v�f������
		for( int j = i + 1; j < h; j++ ){
			if( m_Array[j] < nMin ){	// ��菬�����v�f������������
				iMin = j;
				nMin = m_Array[j];
			}
			else if( m_Array[j] > nMax ){ // ���傫���v�f������������
				iMax = j;
				nMax = m_Array[j];
			}
		}

		// ����ւ�
		Swap( m_Array[iMin], m_Array[i] );
		Swap( m_Array[iMax], m_Array[h] );

		h--;
	}
}

// ================================
// ��r�񐔂Ƒ���񐔂𑪂邽�߂̃\�[�g
// ================================
template <class TYPE>
void COriginalSortArray <TYPE> ::CompSort()
{
	int h = m_iArrayNum - 1; // ��Ԍ��̗v�f�̃C���f�b�N�X
	// �v�f�� - 1 �񃋁[�v
	for( int i = 0; i < h; i++ ){

		// �����l���
		iMin = iMax = i;
		nMin = m_Array[i];
		nMax = m_Array[h];

		// �ŏ��v�f�ƍő�v�f������
		for( int j = i + 1; j < h; j++ ){
			if( m_Array[j] < nMin ){	// ��菬�����v�f������������
				iMin = j;
				nMin = m_Array[j];
				compareCount++; // ��r�񐔁{1
			}
			else if( m_Array[j] > nMax ){ // ���傫���v�f������������
				iMax = j;
				nMax = m_Array[j];
				compareCount++; // ��r�񐔁{�P
			}
		}

		// ����ւ�
		Swap( m_Array[iMin], m_Array[i] ); substituteCount++; // ����񐔁{1
		Swap( m_Array[iMax], m_Array[h] ); substituteCount++; // ����񐔁{1

		h--;
	}
}

#endif