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
	cout << "•Óa‚ð“ü—ÍF";
	cin >> a;
}

void Triangle::set_b(){
	cout << "•Ób‚ð“ü—ÍF";
	cin >> b;
}

void Triangle::set_c(){
	cout << "•Óc‚ð“ü—ÍF";
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
	cout << "•Óa = "<< ob.get_a() << "\n";
	cout << "•Ób = "<< ob.get_b() << "\n";
	cout << "•Óc = "<< ob.get_c() << "\n";
}