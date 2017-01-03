// UserInput.cpp
// ���[�U�[����̓��͂��Ǘ�����N���X
// �쐬���F2016/6/8
// �쐬�ҁF�n� ��

#include "UserInput.h"

#define C( str ) converter[string( #str )] = str

// �R���X�g���N�^
CUserInput::CUserInput( CSeatManager* seatM, CDisplay* disp, CConverter* converter )
	: seatManager( seatM ), display( disp ), converter( converter )
{}

// ���O����
string CUserInput::InputName()
{
	string str;		// ���O���i�[���镶����ϐ�
	cout << "���O����͂��Ă��������B�F";
	cin >> str;	// ����
	return str;
}

// ���Ȑ�����
int CUserInput::InputNum()
{
	int num;	// �\�񂷂���Ȑ����i�[����ϐ�
	bool loop = true;	// �s�����͎��̃��[�v�ϐ�

	cout << "�\�񂷂���Ȃ̐�����͂��Ă��������B�F";
	do{
		if( !( cin >> num ) ){ // 0�ȉ��܂��͋�Ȉȏ�̐��l�̏ꍇ
			cin.clear();
			cin.ignore( INT_MAX, '\n' );
			cout << "�l���s���ł��B������x��蒼���Ă��������B" << endl
					<< "�\�񂷂���Ȃ̐�����͂��Ă��������B�F";
		}else loop = false;
	}while( loop );

	return num;
}

// ���Ȕԍ�����
SEAT_NUM CUserInput::InputSeatNum( string* seatStr )
{
	bool loop = true;			// �s�����͎��̃��[�v�p�̕ϐ�
	SEAT_NUM seatNum;	// ���Ȕԍ����i�[����ϐ�
	string str;						// ���͂��󂯎��ϐ�
	
	do{
		cout << "�\�񂷂���Ȃ̔ԍ�����͂��Ă��������B" << endl
				<< "���͗�" << endl 
				<< "C���3�Ԃ�\�񂵂����ꍇ�FC3" << endl
				<< "���Ȕԍ��F";
		cin >> str;	// ���͂��󂯎��
		*seatStr = str;	// �o�͗p�̕ϐ��ɕ��������
		seatNum = converter -> convert( str );	// �������SEAT_NUM�^�ɕϊ�
		if( seatNum <= 0 || seatNum >= NONE ){	// �s�����͂̏ꍇ
			display -> Display();	// ��ʍX�V
			cout << "���͂��ꂽ�ԍ����s���ł��B" << endl
					<< "���͓��e���m�F�̏�A������x���͂��Ă�������" << endl;
		}else loop = false;	// �������Ƀ��[�v�𔲂���
	}while( loop );

	return seatNum;
}

// ���Ȕԍ�����(����)
string CUserInput::InputSeatNum()
{
	bool loop = true;			// �s�����͎��̃��[�v�p�̕ϐ�
	SEAT_NUM seatNum;	// ���Ȕԍ����i�[����ϐ�
	string str;						// ���͂��󂯎��ϐ�
	
	do{
		cout << "���Ȃ̔ԍ�����͂��Ă��������B" << endl
				<< "���͗�" << endl 
				<< "C���3�Ԃ̏ꍇ�FC3" << endl
				<< "���Ȕԍ��F";
		cin >> str;	// ���͂��󂯎��
		
		seatNum = converter -> convert( str );	// �������SEAT_NUM�^�ɕϊ�
		if( seatNum <= 0 || seatNum >= NONE ){	// �s�����͂̏ꍇ
			display -> Display();	// ��ʍX�V
			cout << "���͂��ꂽ�ԍ����s���ł��B" << endl
					<< "���͓��e���m�F�̏�A������x���͂��Ă�������" << endl;
		}else loop = false;	// �������Ƀ��[�v�𔲂���
	}while( loop );

	return str;
}

// ���͂܂Ƃ�
void CUserInput::InputDataSet( UserData* data )
{
	// ���O�����
	string name = InputName();
	data -> name = name;

	// ���Ȑ������
	int num = InputNum();
	data -> num = num;

	// ���͂������Ȑ��������[�v
	for( int i = 1; i <= num; i++ ){
		bool loop = true;	// ���s�����[�v���邽�߂̃t���O
		string seatNum;	// �m�F�p�̍��Ȕԍ����i�[���镶����

		do{	// ���ȗ\�񂪂ł���܂Ń��[�v
			cout << num << "�Ȓ�" << i << "�Ȗڂ̍��Ȕԍ������" << endl;

			// �\�񂷂���Ȃ̔ԍ������
			SEAT_NUM seat = InputSeatNum( &seatNum );

				if( !seatManager -> Reserve( seat ) ){
					// �\�񎸔s��
					display -> Display();	// ��ʍX�V
					cout << "���Ȕԍ�" << seatNum << "�̍��Ȃ͊��ɗ\�񂳂�Ă��܂��B" << endl;
					
				}else{
					// �\�񐬌���
					display -> Display();	// AA�\���X�V
					cout << "=================================" << endl
							<< "���O" << name << "��" << endl
							<< "���Ȕԍ� " << seatNum << " �̍��Ȃ�\�񂵂܂����B" << endl
							<< "=================================" << endl << endl;
					data -> seatList.push_back( seatNum );	// ���̓f�[�^�ɍ��ȃ��X�g���Z�b�g
					loop = false;	// ���[�v�𔲂���
				}

		}while( loop );
	}
}

// �O������Ăяo���֐�
UserData CUserInput::Input()
{
	UserData data;
	InputDataSet( &data );
	return data;
}