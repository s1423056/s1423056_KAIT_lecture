// ��R�@���z��{�N���X
#include <iostream>
using namespace std;

class XY {
	double x, y; // X �����EY �����̑傫����\��
public:
	XY(double u=1, double v=1) { x=u; y=v; }
	double get_x() { return x; }
	double get_y() { return y; }
};

class Rect : virtual public XY{ // �����`
	int color; // �F�ԍ���\��
	double area; // �ʐ� x*y ��\��
public:
	Rect(int c = 0){color = c; area = get_x()*get_y();}
	int get_col() { return color; }
	double get_area() { return area; }
};

class XYZ : virtual public XY{
	double z; // Z �����̑傫����\��
public:
	XYZ(double w = 1){ z=w;}
	double get_z() { return z; }
};

class Cube : public XYZ,Rect{ // ������
	double volume; // �̐� x*y*z ��\��
public:
	Cube(double u = 1, double v = 1, double w = 1, int c = 0):XY(u,v),XYZ(w),Rect(c){ volume = get_x()*get_y()*get_z(); }
	double get_vol() { return volume; }
	void show();
};

void Cube::show() {
	cout << "x:" << get_x() << "\n";
	cout << "y:" << get_y() << "\n";
	cout << "z:" << get_z() << "\n";
	cout << "�F:" << get_col() << "\n";
	cout << "�̐�:" << get_vol() << "\n";
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