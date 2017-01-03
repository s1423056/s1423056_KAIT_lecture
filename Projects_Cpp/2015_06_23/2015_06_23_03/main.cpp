//　課題３

#include <iostream>
using namespace std;

class samp {
	int a, b;
	public:
	samp(int n, int m) { a = n; b = m; }
	void show() { cout << "(" << a << "," << b << ")\n"; }
};

int main() {
	samp ob[3][2] = {
		// 実行結果を参考にオブジェクトの配列の初期化
		samp(1,2),samp(2,3),samp(3,4),samp(4,5),samp(5,6),samp(6,7)
	};
	samp *p;
	p = (samp *) ob;
	for (int i = 0; i < 6; i++) {
	// ポインタを使って出力
	// ポインタの示すアドレスを1つ後ろにする
		p->show();
		p++;
	}
	return 0;
}