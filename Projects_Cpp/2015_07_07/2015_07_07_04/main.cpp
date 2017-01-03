// ��S�J�[�h�N���X�̉��Z�q�I�[�o�[���[�h

#include <iostream>
#include <stdlib.h>		// ���������[�N���o�̂���
#include <crtdbg.h>	// ���������[�N���o�̂���


using namespace std;

#define _CRTDBG_MAP_ALLOC	// ���������[�N���o�̂���
#define new ::new( _NORMAL_BLOCK, __FILE__, __LINE__ )	// ���������[�N���o�̂���
#define MAX_NUM 100

class Cards {
	char *name[MAX_NUM];
	int number;

public:
	// �R���X�g���N�^
	Cards() { number = 0; }

	// �R�s�[�R���X�g���N�^
	Cards(const Cards &ob);

	// �f�X�g���N�^
	~Cards() {
		// �܂܂�Ă���J�[�h�����ׂ�delete
		for (int i = 0; i < number; i++)
			delete [] name[i];
	}

	// �J�[�h�ǉ�
	void add(char *str);

	// str�Ƃ������O�̃J�[�h���폜
	//int del(char *str);

	// n�ɑΉ�����J�[�h���폜
	// int del(int n);

	// �J�[�h�̐���0�ɂ���
	void cls();

	// �܂܂��J�[�h�����ׂĕ\��
	void show();
	Cards operator+(Cards &ob);			// �J�[�h���m�𑫂����킹��
	Cards &operator=(Cards &ob);		// ���g�̃I�u�W�F�N�g��ob���ڂ�
	Cards &operator+=(Cards &ob);		// ���g�̃I�u�W�F�N�g��ob�𑫂�����
	Cards operator<<(int n);				// �擪����n���̃J�[�h�𔲂��o��
};

// ================================================================
// �R�s�[�R���X�g���N�^
// ================================================================
Cards::Cards( const Cards &ob )
{
	 number = 0;
	for(int i = 0; i < ob.number; i++)
	{
		this -> add( ob.name[i] );
	}
}

// ================================================================
// �J�[�h��ǉ�
// ================================================================
void Cards::add( char *str )
{
	name[number] = new char[strlen(str)+1];
	strcpy( name[number], str );
	number++;
}


// ================================================================
// �J�[�h�̐���0����
// ================================================================
void Cards::cls()
{
	for( int i = 0;i < number; i++ )
	{
		delete[] name[i];	// [i]�Ԃ�char�^�z���delete�i�z���delete��[]������j
	}
	number = 0;
}

// ================================================================
// �܂܂�Ă���J�[�h�����ׂĕ\��
// ================================================================
void Cards::show()
{
	for( int i = 0; i < number; i++ )	// number�̐������J�[�h��\��
	{
		cout << name[i] << endl;
	}
}

// ================================================================
// �J�[�h���m�𑫂����킹��
// ================================================================
Cards Cards::operator+( Cards &ob )
{
	Cards tmp;
	for( int i = 0; i < this -> number; i++ )
	{
		tmp.add( this ->name[i] );
	}
	for( int i = 0; i < ob.number; i++ )
	{
		tmp.add( ob.name[i] );
	}
	return tmp;
}

// ================================================================
// ���g�̃I�u�W�F�N�g��ob���ڂ�
// ================================================================
Cards &Cards::operator=( Cards &ob )
{
	this -> cls();	// ���Ƃ��Ɗ܂܂�Ă����J�[�h�����ׂď���
	// ob�Ɋ܂܂�Ă���J�[�h�����ׂč��I�y�����h�ɒǉ�
	for( int i = 0; i < ob.number; i++ )
	{
		this -> add( ob.name[i] );
	}
	ob.cls();	// ob�Ɋ܂܂�Ă���J�[�h�����ׂď���
	return *this;
}

// ================================================================
// ���g�̃I�u�W�F�N�g��ob�𑫂�����
// ================================================================
Cards &Cards::operator+=(Cards &ob)
{
	// ob�Ɋ܂܂��J�[�h�����ׂč��̃I�y�����h�ɒǉ�����
	for( int i = 0; i < ob.number; i++ )
	{
		this -> add(ob.name[i]);
	}
	ob.cls();	// ob�Ɋ܂܂��J�[�h�����ׂď���
	return *this;
}

// ================================================================
// �擪����n���̃J�[�h�𔲂�����
// ================================================================
Cards Cards::operator<< (int n)
{
	Cards tmp;
	// ���I�y�����h�Ɋ܂܂�Ă���擪����n���̃J�[�h��tmp�ɒǉ�
	for( int i = 0; i < n; i++)
	{
		tmp.add( this -> name[i] );
	}

	// ���I�y�����h�̎c��̃J�[�h��擪�ɋl�߂�
	for( int i = 0; i < n; i++)
	{
		delete[] this -> name[i];
	}
	for( int i = n; i < number; i++ )
	{
		this -> name[i -n] = this -> name[i];
	}

	// ���I�y�����h�̌�납��n��������
	for( int i = number-1; i >= number - n; i--)
	{
		name[i] = NULL;
	}

	// ���I�y�����h�̖��������킹��
	this -> number -= n;

	return tmp;
}

// ================================================================
// ���C���֐�
// ================================================================
int main() {

	_CrtSetDbgFlag( _CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF );

	Cards deck, hand, discard, temp;
	deck.add("����");
	deck.add("�s��");
	deck.add("���");
	deck.add("��q��");
	deck.add("���~");
	deck.add("����");
	hand.add("���");
	hand.add("�n��������");

	cout << "�R�D��\n";
	deck.show();

	cout << "\n��D��\n";
	hand.show();

	cout << "\ntemp=�R�D+��D\n";
	temp = deck + hand;

	cout << "\ntemp��\n";
	temp.show();

	cout << "\n�R�D����2����D�ɉ�����\n";
	hand += deck << 2;

	cout << "\n�R�D��\n";
	deck.show();

	cout << "\n��D��\n";
	hand.show();

	cout << "\n��D���ׂĂ��̂ĎD��\n";
	discard = hand;
	hand.cls();

	cout << "\n��D��\n";
	hand.show();

	cout << "\n�̂ĎD��\n";
	discard.show();

	return 0;
}