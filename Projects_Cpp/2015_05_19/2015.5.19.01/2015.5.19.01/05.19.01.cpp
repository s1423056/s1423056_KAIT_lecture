#include <iostream>
using namespace std;

class area_c1{
public:
	double height;
	double width;
};

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
cout << "長方形 高さ:" << b.get_h() << " 幅:" << b.get_w() << " 面積:" << b.area() << "\n";
cout << "三角形 高さ:" << i.get_h() << " 幅:" << i.get_w() << " 面積:" << i.area() << "\n";
return 0;
}