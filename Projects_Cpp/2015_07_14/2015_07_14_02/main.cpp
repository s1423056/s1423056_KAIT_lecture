// 問2　アクセス制御の確認
#include <iostream>
using namespace std;

class base {
	int a;
public:
	void seta(int n){ a = n;}
	int geta() {return a;}
};

class derived :private base{ // 不完全な宣言
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
	
	// derivedオブジェクトの宣言
	derived ob;

	// オブジェクトのaに変数aの値をbに変数bを設定
	cout << "aに" << a << "を," << "bに" << b << "を設定します\n";
	ob.setab(a,b);
	
	cout << "a*b = " << // オブジェクトの
	// mul()を使って計算結果を出力

	ob.mul() << endl;

	return 0;}