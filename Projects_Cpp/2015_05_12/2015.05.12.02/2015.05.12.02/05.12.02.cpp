#include <iostream>
using namespace std;

class TestClass{
public:
	TestClass();
	~TestClass();
};

TestClass::TestClass(){
	cout<<"�R���X�g���N�^�Ăяo��\n";
}

TestClass::~TestClass(){
	cout << "�f�X�g���N�^�Ăяo��\n";
}

int main(){
	TestClass tc;
	cout << "main()���̃e�X�g�\��\n";
	return 0;
}
/*
int main(){
	cout << "main()���̃e�X�g�\��\n";
	TestClass tc;
	return 0;
}*/