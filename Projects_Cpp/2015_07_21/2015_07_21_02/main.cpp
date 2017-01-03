// ��Q�@���d�p���̊�{�Q
#include <iostream>
using namespace std;

class Position {
	double x, y;
public:
	Position(double u, double v):x(u),y(v){};
	void showpos(){
		cout << "�ʒu�F(" << x << ", " << y << ")" <<endl;
	}
};

class Color {
	int red, green, blue;
public:
	Color(int r, int g, int b):red(r),green(g),blue(b){};
	void showcol(){
		cout << "�F�F(" << red << ", " << green << ", " << blue << ")" << endl;
	}
};

class Graphic : private Position, Color{
	int type;
	double width, height;
public:
	Graphic(int t, double x, double y, double
		w, double h, int r, int g, int b):Position(x,y),Color(r,g,b),type(t),width(w),height(h){};
	void show(){
		switch(type){
		case 0:
			cout << "�`��F �~" << endl;
			break;
		case 1:
			cout << "�`��F �l�p�`" << endl;
			break;
		case 2:
			cout << "�`��F �O�p�`" << endl;
			break;
		}
		showpos();
		cout << "���F" << width << "\t�����F" << height << endl;
		showcol();
		
	}
};

int main() {
	Graphic ob1(1, 3, 4, 1, 2, 255, 0, 0);
	Graphic ob2(2, 5, 6, 7, 8, 0, 255, 0);
	Graphic ob3(3, -1, -2, 10, 10, 0, 0, 255);
	cout << "ob1\n";
	ob1.show();
	cout << "\n";
	cout << "ob2\n";
	ob2.show();
	cout << "\n";
	cout << "ob3\n";
	ob3.show();
	return 0;
}