// ��2�@�A�N�Z�X����̊m�F
#include <iostream>
using namespace std;

class base {
	int a;
public:
	void seta(int n){ a = n;}
	int geta() {return a;}
};

class derived :private base{ // �s���S�Ȑ錾
	int b;
public:
	void setab(int n, int m){ seta(n);b = m; }
	int mul(){
		int n = b*geta();
		return n;
	}
};

int main() {
	int a = 3, b = 5;
	
	// derived�I�u�W�F�N�g�̐錾
	derived ob;

	// �I�u�W�F�N�g��a�ɕϐ�a�̒l��b�ɕϐ�b��ݒ�
	cout << "a��" << a << "��," << "b��" << b << "��ݒ肵�܂�\n";
	ob.setab(a,b);
	
	cout << "a*b = " << // �I�u�W�F�N�g��
	// mul()���g���Čv�Z���ʂ��o��

	ob.mul() << endl;

	return 0;}