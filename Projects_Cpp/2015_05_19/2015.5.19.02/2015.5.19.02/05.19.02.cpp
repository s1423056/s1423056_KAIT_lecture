#include <iostream>
using namespace std;

class area_cl2 {
double height;
double width;
public:
	void set_h(double h){height = h;} // heightに値を設定する関数
	void set_w(double w){width = w;}// widthに値を設定する関数
	double get_h(){return height;}		// heightを返す関数
	double get_w(){return width;}		// widthを返す関数
};

class rectangle:public area_cl2{
public:
	rectangle(double h,double w);
	double area();
};

class isosceles:public area_cl2{
public:
	isosceles(double h,double w);
	double area();
};

rectangle::rectangle(double h,double w){
	set_h(h);
	set_w(w);
}

double rectangle::area(){
	return get_h()*get_w();
}

isosceles::isosceles(double h,double w){
	set_h(h);
	set_w(w);
}

double isosceles::area(){
	return get_w()*get_h()/2.0;
}

int main() {
rectangle b(10.0, 5.0);
isosceles i(4.0, 6.0);
rectangle *pb;
isosceles *pi;

pb = &b;
pi = &i;

cout << "長方形 高さ:" << pb->get_h() << " 幅:" << pb->get_w() << " 面積:" << pb->area() << "\n";
cout << "三角形 高さ:" << pi->get_h() << " 幅:" << pi->get_w() << " 面積:" <<pi->area() << "\n";
return 0;
}