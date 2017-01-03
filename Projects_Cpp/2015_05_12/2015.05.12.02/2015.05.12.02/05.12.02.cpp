#include <iostream>
using namespace std;

class TestClass{
public:
	TestClass();
	~TestClass();
};

TestClass::TestClass(){
	cout<<"コンストラクタ呼び出し\n";
}

TestClass::~TestClass(){
	cout << "デストラクタ呼び出し\n";
}

int main(){
	TestClass tc;
	cout << "main()内のテスト表示\n";
	return 0;
}
/*
int main(){
	cout << "main()内のテスト表示\n";
	TestClass tc;
	return 0;
}*/