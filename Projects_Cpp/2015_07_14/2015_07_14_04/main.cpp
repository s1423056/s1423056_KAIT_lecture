// 問4 継承とコンストラクタ
#include <iostream>
using namespace std;

class base {
	int a;
public:
	base(int n){ a = n; }
	int geta() { return a; }
};

class derived :public base{ // 不完全な宣言
	int b;
public:
	derived( int n, int m):base(n){ b = m;}
	
	int mul(){
		return b * geta();
	}
};

int main() {
	int a = 3, b = 5;
	
	// derivedオブジェクトの宣言
	derived ob(a,b);

	cout << "a*b = " << // オブジェクトの
	// mul()を使って計算結果を出力

	ob.mul() << endl;

	return 0;
}