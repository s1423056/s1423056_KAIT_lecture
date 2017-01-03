// 問1 継承の基本
#include <iostream>
using namespace std;

class base {
	int a;
public:
	void seta(int n){ a = n;}
	int geta() {return a;}
};

class derived :public base{ // 不完全な宣言
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
	
	// derivedオブジェクトの宣言
	derived ob;

	// オブジェクトのaに変数aの値を設定
	cout << "aに" << a << "を設定します\n";
	ob.seta(a);
	

	// オブジェクトのbに変数bの値を設定
	cout << "bに" << b << "を設定します\n";
	ob.setb(b);

	cout << "a*b = " << // オブジェクトの
	// mul()を使って計算結果を出力

	ob.mul() << endl;

	return 0;}