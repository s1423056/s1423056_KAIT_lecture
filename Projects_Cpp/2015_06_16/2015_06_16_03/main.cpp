#include <iostream>
using namespace std;

class Triangle {
	double a, b, c;
public:
	Triangle(double u, double v, double w) {
		a=u; b=v; c=w;
	}
	~Triangle() {
		cout << "�f�X�g���N�^�Ăяo��\n";
	}
	void set_a(double x) { a = x; }
	void set_b(double x) { b = x; }
	void set_c(double x) { c = x; }
	double get_a() { return a; }
	double get_b() { return b; }
	double get_c() { return c; }
	double area();
	void show();
};

double Triangle::area() {
	double s;
	s = (a+b+c) / 2;
	return sqrt(s*(s-a)*(s-b)*(s-c));
}

void Triangle::show() {
	cout << "��a = " << a << "\n";
	cout << "��b = " << b << "\n";
	cout << "��c = " << c << "\n";
	cout << "�ʐ� = " << area() << "\n";
}

int main(){
	Triangle *t = new Triangle(3,4,5);
	t -> show();
	delete t;
	return 0;
}