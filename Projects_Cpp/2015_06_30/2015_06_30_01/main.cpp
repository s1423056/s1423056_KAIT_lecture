// ��1
#include <iostream>
using namespace std;

class strtype {
	char *p;
public:
	strtype(char *s);
	strtype(char *s, int n);
	~strtype(){ if(p) delete[] p;}
	char *get() { return p; }
};

strtype::strtype( char *s ){
	int l;
	l = strlen( s )+1;
	p = new char[l];// �������̓��I�m��
	if( !p ){	// ���������m�ۂł��ĂȂ��ꍇ
		cout << "memory error!" << endl;	
		exit( 1 );// �G���[�I��
	}
	strcpy( p, s );
}

strtype::strtype( char *s, int n ){
	int l = strlen( s )*n +1;
	p = new char[l];//�������̓��I�m��
	if( !p ){	// ���������m�ۂł��ĂȂ��ꍇ
		cout << "memory error!" << endl;
		exit( 1 );	// �G���[�I��
	}
	*p = '\0';
	for(int i = 0;i < n;i++){
		strcat( p, s );	// n��p��s��A��
	}
}

void show( char *s ){
	cout << s << endl;	//�n���ꂽ�������\��
}

int main()
{
	strtype s1 = strtype( "Good!" );
	strtype s2 = strtype( "Good!",5 );
	cout << "s1:";
	show( s1.get() );	// show��s1�̕������n��
	cout << "s2:";
	show( s2.get() );// show��s2�̕������n��

	return 0;
}