#include <iostream>
using namespace std;

class Triangle{
	double a,b,c;
public:
	void set_a();
	void set_b();
	void set_c();
	double get_a();
	double get_b();
	double get_c();
};

void Triangle::set_a(){
	cout << "��a����́F";
	cin >> a;
}

void Triangle::set_b(){
	cout << "��b����́F";
	cin >> b;
}

void Triangle::set_c(){
	cout << "��c����́F";
	cin >> c;
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
	Triangle ob;
	ob.set_a();
	ob.set_b();
	ob.set_c();
	cout << "��a = "<< ob.get_a() << "\n";
	cout << "��b = "<< ob.get_b() << "\n";
	cout << "��c = "<< ob.get_c() << "\n";
}