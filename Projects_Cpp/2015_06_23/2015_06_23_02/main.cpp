// 課題2

#include <iostream>
using namespace std;
class Coord { 
	double x, y, z;
public: 
	void set(double u, double v, double w) { x = u; y = v; z = w; } 
	void show(); 
}; 
void Coord::show() { cout << "(" << x << "," << y << "," << z << ")"; }

void setCoord1(Coord ob) { // 値渡し
	double u, v, w; 
	cout << "数字を3つ入力してください："; 
	cin >> u >> v >> w; 
	ob.set(u, v, w); // 実際には値を設定できない 

}

void setCoord2(Coord *ob) { // ポインタ渡し 
	// 上記関数を参考に値を設定するコードを記述 
	double u, v, w; 
	cout << "数字を3つ入力してください："; 
	cin >> u >> v >> w; 
	ob->set(u, v, w);
} 

void setCoord3(Coord &ob) { // 参照渡し 
	// 上記関数を参考に値を設定するコードを記述 
	double u, v, w; 
	cout << "数字を3つ入力してください："; 
	cin >> u >> v >> w; 
	ob.set(u, v, w); 
}

int main(){
	Coord obj;

	obj.set(1.1, 2.3, 5.5);
	cout << " オブジェクトの初期値：";
	obj.show();
	cout << "\n\n";

	cout << "値渡しで関数にオブジェクトを渡します\n";
	setCoord1(obj);
	cout << "オブジェクトの値：";
	obj.show();
	cout << "\n\n";

	cout << "ポインタ渡しで関数にオブジェクトを渡します\n";
	// 上記を参考に関数呼び出しと値の表示コードを記述
	Coord *p_obj = &obj;
	setCoord2(p_obj);
	obj.show();
	cout << "\n\n";

	cout << "参照渡しで関数にオブジェクトを渡します\n";
	// 上記を参考に関数呼び出しと値の表示のコードを記述
	setCoord3(obj);
	obj.show();
	cout << "\n\n";

	return 0;
}