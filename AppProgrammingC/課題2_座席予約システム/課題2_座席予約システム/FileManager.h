// FileManager.h
// �O���t�@�C���������N���X
// �쐬���F2016/5/19
// �쐬�ҁF�n� ��

#ifndef _FILEMANAGER_H
#define _FILEMANAGER_H

#include "SeatManagar.h"
#include "UserInput.h"
#include <fstream>
#include <iostream>
using namespace std;

class CFileManager
{
private:
	ifstream ifs;		// �t�@�C�����̓X�g���[��
	ofstream ofs;	// �t�@�C���o�̓X�g���[��
	CConverter* converter;	// string�^����SEAT_NUM�ɕϊ�����N���X�̃|�C���^
	string ExPathWithoutExt( string &filename );	// �g���q���������t�@�C�������擾
	void importLoop( string filenameHead );	// ���̂����֐�

public:
	// �R���X�g���N�^
	CFileManager( CConverter* converter );

	// �t�@�C���ǂݍ���
	// filename�F�t�@�C����
	bool ImportFile( const string filename, CSeatManager* seatM );

	// �t�@�C���ǂݍ���
	string ImportFile( const string filename ){
		string str, filenameStr;
		filenameStr = filename + ".txt";
		ifs.open( filenameStr );
		if( ifs.fail() )
			cerr << "���s" << endl;
		getline( ifs, str );
		return str;	
	}

	// �t�@�C�������o��
	// filename�F�t�@�C����(���Ȕԍ�)
	bool ExportFile( const string filename, UserData data );

};

#endif