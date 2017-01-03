// SortTest.h
// �\�[�g���؂��s���N���X

#ifndef _SORTTEST_H
#define _SORTTEST_H

#include "Array.h"
#include "Timer.h"
#include <fstream>

class CSortTest
{
private:
	CTimer timer;			// �^�C�}�[
	LONGLONG count;	// ���σJ�E���g��
	LONGLONG time;		// ���ώ���
	LONGLONG minCount, maxCount;	// �ő�J�E���g���A�ŏ��J�E���g��
	LONGLONG minTime, maxTime;		// �ő厞�ԁA�ŏ�����

	// �e�X�g���s
	// ary�F�\�[�g���s���z��
	// arrayNum�F�z��̗v�f��
	// testNum�F���s��
	template <class TYPE>
	void Test( CArray<TYPE>* ary, const int arrayNum, const int testNum )
	{
		ary -> CompSort();	// ��r�񐔂Ƒ���񐔂��v��

		for( int i = 0; i < testNum; i++ ){
			ary -> Init( arrayNum );	// �z�񏉊���

			timer.Begin();		// �v���J�n
			ary -> Sort();		// �\�[�g���s
			timer.End();			// �v���I��

			// ���̂��Ɖ��x��timer�̕ϐ����g���̂ňꎞ�ϐ��ɕۑ����Ă���
			LONGLONG tCount = timer.GetCount();
			LONGLONG tTime = timer.GetTime();

			if( i == 0 ){
				// 1��ڂ̌��ʂ��ő�E�ŏ��̒l�Ƃ��ĕۑ����Ă���
				maxCount = minCount = tCount;
				maxTime = minTime = tTime;
			}else{
				// 2��ڈȍ~�͍ő傩�ŏ��������؂��āA�ϐ����X�V
				if( maxCount < tCount ) maxCount = tCount;
				else if( minCount > tCount ) minCount = tCount;
				if( maxTime < tTime ) maxTime = tTime;
				else if( minTime > tTime ) minTime = tTime;
			}

			count += tCount;	// �J�E���g�������Z
			time += tTime;		// ���Ԃ����Z

			/*
			// �R���\�[���\��
			cout << "============" << i << "���" << "============" << endl;
			cout << "���ԁF"	<< tTime << "�~���b" << endl;
			cout << "CPU�J�E���g���F" << tCount << "�J�E���g" << endl;
			cout << endl;
			*/
		}

		count /= testNum;		// ���σJ�E���g�����v�Z
		time /= testNum;		// ���ώ��Ԃ��v�Z

		// ���ʕ\��
		cout << "============����============" << endl;
		cout << arrayNum << "�̗v�f����" << testNum << "�񎎍s���܂����B" << endl;
		cout << "���ώ��ԁF" << time << "�~���b" << endl;
		cout << "���σJ�E���g���F" << count << "�J�E���g" << endl;
		cout << "��r�񐔁F" << ary -> GetCompareCount() << "��" << endl;
		cout << "����񐔁F" << ary -> GetSubstituteCount() << "��" << endl;
		cout << "--------------------------------" << endl;
		cout << "�ő厞�ԁF" << maxTime << "�~���b" << endl;
		cout << "�ŏ����ԁF" << minTime << "�~���b" << endl;
		cout << "�ő�J�E���g���F" << maxCount << "�J�E���g" << endl;
		cout << "�ŏ��J�E���g���F" << minCount << "�J�E���g" << endl << endl;
	}

public:
	// �R���X�g���N�^
	CSortTest(){
		// �ϐ���0�ŏ�����
		time = 0; count = 0; 
		minCount = 0; maxCount = 0;
		minTime = 0; maxTime = 0;
	}

	// ���σJ�E���g���擾
	LONGLONG GetCount(){ return count; }

	// ���ώ��Ԏ擾
	LONGLONG GetTime(){ return time; }


	// main�֐��ŌĂяo���֐�
	// �����Ŏ��s�񐔂�100��ɌŒ�

	// �o�u���\�[�g
	template <class TYPE>
	void BubbleSortTest( const int arrayNum )
	{	
		// �\�[�g���s���z��N���X��錾
		CArray<TYPE>* ary = new CBubbleSortArray<TYPE>( arrayNum );
		Test( ary, arrayNum, 100 );	// �e�X�g���s
		delete[] ary; // ��Еt��
	}

	// �I��@�\�[�g
	template <class TYPE>
	void SelectSortTest( const int arrayNum )
	{
		// �\�[�g���s���z��N���X��錾
		CArray<TYPE>* ary = new CSelectSortArray<TYPE>( arrayNum );
		Test( ary, arrayNum, 100 );	// �e�X�g���s
		delete[] ary; // ��Еt��
	}

	// �N�C�b�N�\�[�g
	template <class TYPE>
	void QuickSortTest( const int arrayNum )
	{
		// �\�[�g���s���z��N���X��錾
		CArray<TYPE>* ary = new CQuickSortArray<TYPE>( arrayNum );
		Test( ary, arrayNum, 100 );	// �e�X�g���s
		delete[] ary; // ��Еt��
	}

	// �I���W�i���\�[�g
	template <class TYPE>
	void OriginalSortTest( const int arrayNum )
	{
		// �\�[�g���s���z��N���X��錾
		CArray<TYPE>* ary = new COriginalSortArray<TYPE>( arrayNum );
		Test( ary, arrayNum, 100 );	// �e�X�g���s
		delete[] ary; // ��Еt��
	}
};

#endif