// ��4 �p���ƃR���X�g���N�^
#include <iostream>
using namespace std;

class base {
	int a;
public:
	base(int n){ a = n; }
	int geta() { return a; }
};

class derived :public base{ // �s���S�Ȑ錾
	int b;
public:
	derived( int n, int m):base(n){ b = m;}
	
	int mul(){
		return b * geta();
	}
};

int main() {
	int a = 3, b = 5;
	
	// derived�I�u�W�F�N�g�̐錾
	derived ob(a,b);

	cout << "a*b = " << // �I�u�W�F�N�g��
	// mul()���g���Čv�Z���ʂ��o��

	ob.mul() << endl;

	return 0;
}