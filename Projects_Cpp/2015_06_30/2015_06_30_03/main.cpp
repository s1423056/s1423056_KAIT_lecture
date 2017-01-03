// ��3
#include <iostream>
using namespace std;

class strtype {
	char *p;
public:
	strtype(char *s = NULL, int n = 1); // �f�t�H���g�����𗘗p
	strtype( const strtype &o ); // �R�s�[�R���X�g���N�^
	~strtype() { delete [] p; }
	char *get() { return p; }
};

strtype::strtype( char *s, int n){
	int l = strlen(s)*n+1;
	p = new char[l];
	if(!p){
		cout << "memory error!" << endl;
		exit(1);
	}
	*p = '\0';
	for(int i = 0;i<n;i++)strcat(p,s);
}

strtype::strtype( const strtype &o ){
	int l;
	l = strlen(o.p)+1;
	
	p = new char[l];
	if(!p){
		cout << "memory error!" << endl;
		exit(1);
	}
	strcpy(p, o.p);
}

int ccount( strtype x, char c )
{
	// ���� c �̐���Ԃ�
	int count = 0;
	int length = strlen(x.get());
	char *str = x.get();
	for(int i = 0; i < length; i++){
		if(*str == c)count++;
		str++;
	}
	return count;
}

int main(){
	char ch1[100],ch2[100];
	int c;
	char a;
	cout << "������s1��ݒ肵�܂��B"<< endl;
	cout << "���������͂��Ă��������B�F";
	cin >> ch1;
	cout << "�J��Ԃ�������s2��ݒ肵�܂��B"<< endl;
	cout << "���������͂��Ă��������B�F";
	cin >> ch2;
	cout << "�J��Ԃ��񐔂���͂��Ă��������B�F";
	cin >> c;
	cout << "������s1��s2�Ɋ܂܂�邠�镶���̐��𐔂��܂��B" << endl;
	cout << "��������͂��Ă��������F";
	cin >> a;
	strtype s1 = strtype( ch1 );
	strtype s2 = strtype( ch2, c );
	cout << "s1 ��" << a << "�̐��F" << ccount( s1,a )<< endl;
	cout << "s2 ��" << a << "�̐��F" << ccount( s2,a )<< endl;
	cout << "s1�F" << s1.get() << endl;
	cout << "s2�F" << s2.get() << endl;
	return 0;
}