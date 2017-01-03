// Array.h
// ���܂��܂Ȍ^�̔z��������N���X�錾

#ifndef _ARRAY_H
#define _ARRAY_H

#include <iostream>
#include <stdlib.h>

template <class TYPE>
class CArray
{
protected:
	TYPE* m_Array;		// �z��
	int m_iArrayNum;	// �z��̗v�f��
	int compareCount;	// ��r��
	int substituteCount;	// �����

private:
	// ������
	void Init();

	// ���
	void Release();

		// �C���f�b�N�X�`�F�b�N
	void CheckIndex( const int index ) const;

public:
	// �R���X�g���N�^
	explicit CArray( const int num );

	// �R�s�[�R���X�g���N�^
	CArray( const CArray <TYPE> & rother );

	// �f�X�g���N�^
	virtual ~CArray();

	// �z��ɐ��l�������_���œ���鏉����
	// val : �z��̗v�f��
	void Init( const int val );
	
	// �\�[�g���s
	virtual void Sort(){};

	// ��r�񐔁A����񐔂𑪂邽�߂̃\�[�g
	virtual void CompSort(){};
	
	// �v�f�ւ̃A�N�Z�X
	TYPE Get( const int index ) const;
	void Set( const int index, const TYPE value );
	
	// �����o�̎Q��
	TYPE& operator []( unsigned int index );
	TYPE& operator []( int index );
	TYPE operator []( unsigned int index ) const;
	TYPE operator []( int index ) const;

	// �z��̒��ڎQ��
	operator const TYPE* () const;

	// �z�񂪗L�����ǂ���
	bool IsValid() const;

	// �z��̗v�f�����擾
	int ArrayNum() const;

	// �z��̃T�C�Y���擾
	int ArraySize() const;

	// ��r�񐔂��擾
	int GetCompareCount() const;

	// ����񐔂��擾
	int GetSubstituteCount() const;

	// �z��̃R�s�[
	bool Copy( const CArray <TYPE> & rother );

	// =���Z�q�̃I�[�o�[���[�h
	CArray <TYPE> & operator =( const CArray <TYPE> & rother );

	// �v�f�̓���ւ�
	void Swap( TYPE& val1, TYPE& val2 );

	// �v�f��\��
	void Disp();
};


// �R���X�g���N�^
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

// �R�s�[�R���X�g���N�^
template <class TYPE>
CArray <TYPE> ::CArray( const  CArray <TYPE> & rother )
{
	Init();
	Copy( rother );
}

// �f�X�g���N�^
template <class TYPE>
CArray <TYPE> ::~CArray()
{
	Release();
}

// �z��Ƀ����_���ɐ��l�����鏉����
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

// �����o�̎Q��
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

// �z��̒��ڎQ��
template <class TYPE>
inline CArray <TYPE> ::operator const TYPE*() const
{
	return m_Array;
}

// �v�f���擾
template <class TYPE>
TYPE CArray <TYPE> ::Get( const int index ) const
{
	CheckIndex( index );
	return m_Array[index];
}

// �v�f�ɐ�����
template <class TYPE>
void CArray <TYPE> ::Set( const int index, const TYPE value )
{
	CheckIndex( index );
	m_Array[index] = value;
}

// �z��̃R�s�[
template <class TYPE>
bool CArray <TYPE> ::Copy( const CArray& rother )
{
	// ���g�̓R�s�[���Ȃ�
	if( this == &rother )
		return true;

	Release();	// �z�񂪊m�ۂ���Ă���Ƃ��̓��������
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

// �����Z�q�̃I�[�o�[���[�h
template <class TYPE>
CArray <TYPE> & CArray <TYPE> ::operator =( const CArray& rother )
{
	Copy( rother );
	return *this;
}

// �C���f�b�N�X�`�F�b�N
template <class TYPE>
void CArray <TYPE> ::CheckIndex( const int index ) const
{
	if( (unsigned int)index < (unsigned int)m_iArrayNum )
		return;

	cout << "�C���f�b�N�X���s���ł�" << endl
			<< "�l�F" << index << endl;
	exit( 1 );
}

// �z�񂪗L�����ǂ���
template <class TYPE>
inline bool CArray <TYPE> ::IsValid() const
{
	return m_Array != NULL;
}

// �z��̗v�f�����擾
template <class TYPE>
inline int CArray <TYPE> ::ArrayNum() const
{
	return m_iArrayNum;
}

// �z��̃T�C�Y���擾
template <class TYPE>
inline int CArray <TYPE> ::ArraySize() const
{
	return m_iArrayNum * sizeof *m_Array;
}

// ��r�񐔂��擾
template <class TYPE>
inline int CArray <TYPE> ::GetCompareCount() const
{
	return compareCount;
}

// ����񐔂��擾
template <class TYPE>
inline int CArray <TYPE> ::GetSubstituteCount() const
{
	return substituteCount;
}

// ������
template <class TYPE>
void CArray <TYPE> ::Init()
{
	m_Array = NULL;
	m_iArrayNum = 0;
	compareCount = 0;
	substituteCount = 0;
}

// ���
template <class TYPE>
void CArray <TYPE> ::Release()
{
	if( IsValid() == true ){
		delete[] m_Array;
		Init();
	}
};

// �v�f�̓���ւ�
template <class TYPE>
void CArray <TYPE> ::Swap( TYPE& val1, TYPE& val2 )
{
	TYPE temp = val1;
	val1 = val2;
	val2 = temp;
}

// �v�f��\��
template <class TYPE>
void CArray <TYPE> ::Disp()
{
	for( int i = 0; i < m_iArrayNum; i++ ){
		cout << i << " : " << m_Array[i] << endl;
	}
}

#endif