#include <iostream>
using namespace std;

class area_cl2 {
double height;
double width;
public:
	void set_h(double h){height = h;} // height�ɒl��ݒ肷��֐�
	void set_w(double w){width = w;}// width�ɒl��ݒ肷��֐�
	double get_h(){return height;}		// height��Ԃ��֐�
	double get_w(){return width;}		// width��Ԃ��֐�
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

cout << "�����` ����:" << pb->get_h() << " ��:" << pb->get_w() << " �ʐ�:" << pb->area() << "\n";
cout << "�O�p�` ����:" << pi->get_h() << " ��:" << pi->get_w() << " �ʐ�:" <<pi->area() << "\n";
return 0;
}