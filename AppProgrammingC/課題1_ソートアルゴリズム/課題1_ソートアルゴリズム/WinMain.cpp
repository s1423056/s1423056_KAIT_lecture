// WinMain.cpp
// ���C���֐����L�q

#include <iostream>
#include "BubbleSortArray.h"
#include "SelectSortArray.h"
#include "QuickSortArray.h"
#include "OriginalSortArray.h"
#include "SortTest.h"
using namespace std;

int main()
{
	// �e�X�^�[��錾
	CSortTest tester;
	/*
	cout << "########�o�u���\�[�g<int>########" << endl;
	tester.BubbleSortTest<int>( 100 );
	tester.BubbleSortTest<int>( 500 );
	tester.BubbleSortTest<int>( 1000 );
	tester.BubbleSortTest<int>( 5000 );
	tester.BubbleSortTest<int>( 10000 );
	cout << "########�o�u���\�[�g<float>########" << endl;
	tester.BubbleSortTest<float>( 100 );
	tester.BubbleSortTest<float>( 500 );
	tester.BubbleSortTest<float>( 1000 );
	tester.BubbleSortTest<float>( 5000 );
	tester.BubbleSortTest<float>( 10000 );
	
	cout << "########�I��@<int>########" << endl;
	tester.SelectSortTest<int>( 100 );
	tester.SelectSortTest<int>( 500 );
	tester.SelectSortTest<int>( 1000 );
	tester.SelectSortTest<int>( 5000 );
	tester.SelectSortTest<int>( 10000 );
	cout << "########�I��@<float>########" << endl;
	tester.SelectSortTest<float>( 100 );
	tester.SelectSortTest<float>( 500 );
	tester.SelectSortTest<float>( 1000 );
	tester.SelectSortTest<float>( 5000 );
	tester.SelectSortTest<float>( 10000 );
	
	cout << "########�N�C�b�N�\�[�g<int>########" << endl;
	tester.QuickSortTest<int>( 100 );
	tester.QuickSortTest<int>( 500 );
	tester.QuickSortTest<int>( 1000 );
	tester.QuickSortTest<int>( 5000 );
	tester.QuickSortTest<int>( 10000 );
	cout << "########�N�C�b�N�\�[�g<float>########" << endl;
	tester.QuickSortTest<float>( 100 );
	tester.QuickSortTest<float>( 500 );
	tester.QuickSortTest<float>( 1000 );
	tester.QuickSortTest<float>( 5000 );
	tester.QuickSortTest<float>( 10000 );
	
	cout << "########�I���W�i���\�[�g<int>########" << endl;
	tester.OriginalSortTest<int>( 100 );
	tester.OriginalSortTest<int>( 500 );
	tester.OriginalSortTest<int>( 1000 );
	tester.OriginalSortTest<int>( 5000 );
	tester.OriginalSortTest<int>( 10000 );
	cout << "########�I���W�i���\�[�g<float>########" << endl;
	tester.OriginalSortTest<float>( 100 );
	tester.OriginalSortTest<float>( 500 );
	tester.OriginalSortTest<float>( 1000 );
	tester.OriginalSortTest<float>( 5000 );
	tester.OriginalSortTest<float>( 10000 );
	*/

	CBubbleSortArray <int>ary( 100 );
	ary.Init( 100 );
	ary.Disp();
	ary.Sort();
	ary.Disp();
}