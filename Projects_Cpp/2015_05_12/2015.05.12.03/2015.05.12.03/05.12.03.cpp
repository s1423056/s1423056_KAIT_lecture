#include <iostream>
#include <math.h>
using namespace std;

class Triangle{
	double a,b,c,s;
public:
	Triangle(double leng_a, double leng_b, double leng_c);
	double get_a();
	double get_b();
	double get_c();
	double area();
};

Triangle::Triangle(double leng_a, double leng_b, double leng_c){
	a = leng_a;
	b = leng_b;
	c = leng_c;
	s = (a+b+c)/2.0;
}

double Triangle::area(){
	return sqrt(s*(s-a)*(s-b)*(s-c));
}

double Triangle::get_a(){
	return a;
}

double Triangle::get_b(){
	return b;
}

double Triangle::get_c(){
	return c;
}

int main(){
	Triangle ob(3.0,4.0,5.0);
	cout << "•Óa = "<< ob.get_a() << "\n";
	cout << "•Ób = "<< ob.get_b() << "\n";
	cout << "•Óc = "<< ob.get_c() << "\n";
	cout << "–ÊÏ = "<< ob.area() << "\n";
	return 0;
}