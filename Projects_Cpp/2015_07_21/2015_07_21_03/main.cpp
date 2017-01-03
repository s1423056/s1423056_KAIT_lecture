// 問３　仮想基本クラス
#include <iostream>
using namespace std;

class XY {
	double x, y; // X 方向・Y 方向の大きさを表す
public:
	XY(double u=1, double v=1) { x=u; y=v; }
	double get_x() { return x; }
	double get_y() { return y; }
};

class Rect : virtual public XY{ // 長方形
	int color; // 色番号を表す
	double area; // 面積 x*y を表す
public:
	Rect(int c = 0){color = c; area = get_x()*get_y();}
	int get_col() { return color; }
	double get_area() { return area; }
};

class XYZ : virtual public XY{
	double z; // Z 方向の大きさを表す
public:
	XYZ(double w = 1){ z=w;}
	double get_z() { return z; }
};

class Cube : public XYZ,Rect{ // 直方体
	double volume; // 体積 x*y*z を表す
public:
	Cube(double u = 1, double v = 1, double w = 1, int c = 0):XY(u,v),XYZ(w),Rect(c){ volume = get_x()*get_y()*get_z(); }
	double get_vol() { return volume; }
	void show();
};

void Cube::show() {
	cout << "x:" << get_x() << "\n";
	cout << "y:" << get_y() << "\n";
	cout << "z:" << get_z() << "\n";
	cout << "色:" << get_col() << "\n";
	cout << "体積:" << get_vol() << "\n";
}

int main() {
	Cube ob1;
	Cube ob2(2, 3, 4, 5); // (x, y, z, color)
	cout << "ob1\n";
	ob1.show();
	cout << "\nob2\n";
	ob2.show();
	return 0;
}