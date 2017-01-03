// FileManager.cpp
// �t�@�C�����o�͊Ǘ����s���N���X
// �쐬���F2016/6/7
// �쐬�ҁF�n� ��

#include "FileManager.h"

// �R���X�g���N�^
CFileManager::CFileManager( CConverter* converter ) : converter( converter )
{}

// �g���q���������t�@�C�������擾
string CFileManager::ExPathWithoutExt( string &filename )
{
	string seatStr;	// string�^���Ȕԍ�
	string::size_type pos;	// �����񒆂̈ʒu
	if( ( pos = filename.find_last_of( "." ) ) == string::npos )
		return filename;

	return filename.substr( 0, pos );
}

// �t�@�C������
bool CFileManager::ImportFile( const string filename, CSeatManager* seatM )
{
	bool flag = false;	// ��������true�ɒu��������
	string seatNum = filename;	// �g���q�Ȃ��̃t�@�C�����ɂ��邽�߂̕�����
	ifs.open( filename );

	if( ifs ){	// �t�@�C�����J����	
		string seatStr = ExPathWithoutExt( seatNum );	// �g���q���������t�@�C������
		SEAT_NUM seatNum = converter -> convert( seatStr );	// �t�@�C����������Ȕԍ���
		seatM -> Reserve( seatNum );	// �t�@�C��������Ƃ������Ƃ͍��ȗ\��ς݂ł���
		flag = true;
	}

	ifs.close();	// ����
	return flag;
}

// �t�@�C���o��
bool CFileManager::ExportFile( const string filename, UserData data )
{
	bool flag = false;	// ��������true�ɒu��������
	string str = data.name;
	ofs.open( filename, ios::out );
	if( ofs ){	// �t�@�C��������ꍇ�\��ς�	
		// �t�@�C�������݂��Ȃ��ꍇ
		ofs << str << endl;	// �t�@�C�����쐬���ă��[�U�[������������
		if( !ofs.fail() )flag = true;
	}
	ofs.close();	// ����
	return flag;
}
