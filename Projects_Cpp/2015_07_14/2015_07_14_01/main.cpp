// ��1 �p���̊�{
#include <iostream>
using namespace std;

class base {
	int a;
public:
	void seta(int n){ a = n;}
	int geta() {return a;}
};

class derived :public base{ // �s���S�Ȑ錾
	int b;
public:
	void setb(int n){ b = n; }
	int mul(){
		int n = b*geta();
		return n;
	}
};

int main() {
	int a = 3, b = 5;
	
	// derived�I�u�W�F�N�g�̐錾
	derived ob;

	// �I�u�W�F�N�g��a�ɕϐ�a�̒l��ݒ�
	cout << "a��" << a << "��ݒ肵�܂�\n";
	ob.seta(a);
	

	// �I�u�W�F�N�g��b�ɕϐ�b�̒l��ݒ�
	cout << "b��" << b << "��ݒ肵�܂�\n";
	ob.setb(b);

	cout << "a*b = " << // �I�u�W�F�N�g��
	// mul()���g���Čv�Z���ʂ��o��

	ob.mul() << endl;

	return 0;}