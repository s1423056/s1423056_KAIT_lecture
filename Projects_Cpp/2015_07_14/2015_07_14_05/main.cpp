// ��S�J�[�h�N���X�̉��Z�q�I�[�o�[���[�h

#include <iostream>
#include <time.h>		// ���������̂���
#include <stdlib.h>		// ���������[�N���o�̂���
#include <crtdbg.h>	// ���������[�N���o�̂���

using namespace std;	// ������

#define _CRTDBG_MAP_ALLOC	// ���������[�N���o�̂���
#define new ::new( _NORMAL_BLOCK, __FILE__, __LINE__ )		// ���������[�N���o�̂���

#define MAX_NUM 100

class Cards {
	char *name[MAX_NUM];
	int number;

public:
	// �R���X�g���N�^
	Cards() { number = 0; }

	// �R�s�[�R���X�g���N�^
	Cards( const Cards &ob );

	// �f�X�g���N�^
	~Cards() {
		// �܂܂�Ă���J�[�h�����ׂ�delete
		for (int i = 0; i < number; i++)
			delete [] name[i];
	}

	// �J�[�h�ǉ�
	void add( char *str);

	// str�Ƃ������O�̃J�[�h���폜
	int del( char *str );

	// n�ɑΉ�����J�[�h���폜
	 int del( int n );

	// �J�[�h�̐���0�ɂ���
	void cls();

	// �܂܂��J�[�h�����ׂĕ\��
	void show();

	// �����_���ɕ��בւ�
	void shuffle();

	// �J�[�h���̏����ɕ��ׂ���
	void sort();

	// �z��̓Y���� n �Ԃ��� m ���J�[�h�����o��
	Cards draw( int n, int m );

	Cards operator+( Cards &ob );		// �J�[�h���m�𑫂����킹��
	Cards &operator=( Cards &ob );		// ���g�̃I�u�W�F�N�g��ob���ڂ�
	Cards &operator+=( Cards &ob );	// ���g�̃I�u�W�F�N�g��ob�𑫂�����
	Cards operator<<( int n );				// �擪����n���̃J�[�h�𔲂��o��
	char *operator[]( int i );					// �Y�������Z�q�ŃJ�[�h�������o��
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
// str�Ƃ������O�̃J�[�h���폜
// ================================================================
int Cards::del( char *str )
{
	int i;
	for(i = 0; i < number; i++)
	{
		if( !strcmp( name[i], str ) )
		{
			delete[] name[i];
			while(i+1 < number)
			{
				name[i] = name[i+1];
				i++;
			}
			number--;
			return 1;
		}
	}
	return 0;
}

// ================================================================
// n�ɑΉ�����J�[�h���폜
// ================================================================
int Cards::del( int n )
{
	int i;
	if( n < number ){
		delete[] name[n];
		i = n;
		while(i+1 < number){
			name[i] = name[i+1];
			i++;
		}
		number--;
		return 1;
	}
	return 0;
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
// �����_���ɕ��ׂ���
// ================================================================
void Cards::shuffle()
{
	char *temp;
	srand( (unsigned int)time( NULL ) );
	for( int i = 0 ;i < 1000; i++ )
	{
		int n1 = rand() % number;
		int n2 = rand() % number;
		temp = name[n1];
		name[n1] = name[n2];
		name[n2] = temp;
	}
}

// ================================================================
// �J�[�h���������ɕ��בւ�
// ================================================================
void Cards::sort()
{
	// �ォ�珇�ɕ��בւ���
	for(int i = 0; i < number-1;i++)
	{
		for(int j = i+1;j < number; j++)
		{
			if(name[i][0] > name[j][0])
			{
				char* temp = name[i];
				name[i] = name[j];
				name[j] = temp;
			}
			else if(name[i][0] == name[j][0]){	// �����������ꍇ
				// �Ⴄ�������ł�܂�1��������r
				for( int n = 1;n < MAX_NUM;n++)
				{
					if(name[i][n] != name[i][n])
					{
						char* temp = name[i];
						name[i] = name[j];
						name[j] = temp;
						break;
					}
				}
			}
		}
	}
}

// ================================================================
// �z��̓Y����n�Ԃ���m���J�[�h�����o��
// ================================================================
Cards Cards::draw( int n, int m = 1 )
{
	Cards temp;

	if( n>= 0 && n+m <= number )
	{
		for( int i = 0; i < m; i++ )
		{
			temp.add(name[n]);
			this -> del(n);
		}
	}
	return temp;
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
Cards &Cards::operator+=( Cards &ob )
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
Cards Cards::operator<< ( int n )
{
	Cards tmp;

	// �擪����n���̃J�[�h��tmp�ɒǉ�
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

	// ��납��n��������
	for( int i = number-1; i >= number - n; i--)
	{
		name[i] = NULL;
	}

	// ���������킹��
	this -> number -= n;

	return tmp;
}

// ================================================================
// �Y�������Z�q�ŃJ�[�h�������o��
// ================================================================
char *Cards::operator[]( int i )
{
	if(i >= 0 && i < number )
		return name[i];
	else
		return "error";
}

// ================================================================
// ���C���֐�
// ================================================================
int main() {

	_CrtSetDbgFlag( _CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF );

	Cards deck, hand;
	deck.add("Manabarbs");
	deck.add("Birds of Paradise");
	deck.add("Shivan Dragon");
	deck.add("Nightmare");
	deck.add("Royal Assassin");
	deck.add("Clone");
	deck.add("Mahamoti Djinn");
	deck.add("Hypnotic Specter");

	cout << "�R�D��\��\n";
	deck.show();

	cout << "\n�V���b�t��\n";
	deck.shuffle();
	deck.show();

	cout << "\n�\�[�g\n";
	deck.sort();
	deck.show();

	cout << "\n�R�D��6���ڂ̃J�[�h����D��\n";
	hand = deck.draw(5);

	cout << "\n�R�D��3���ڂ���2������D��\n";
	hand += deck.draw(2, 2);

	cout << "\n�R�D��\��\n";
	deck.show();

	cout << "\nfor�����g���Ď�D��3���\��\n";
	for (int i = 0; i < 3; i++)
		cout << hand[i] << "\n";

	return 0;

}