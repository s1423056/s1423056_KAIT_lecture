#include <iostream>
using namespace std;

class myclass{
	int a;
	int b;
public:
	void set_a(int num);
	int get_a();
	void set_b(int num);
	int get_b();
};

void myclass::set_a(int num){
	a = num;
}

int myclass::get_a(){
	return a;
}

void myclass::set_b(int num){
	b = num;
}

int myclass::get_b(){
	return b;
}

int main(){
	myclass ob;

	ob.set_a(10);
	ob.set_b(99);

	cout << ob.get_a() << "\n";
	cout << ob.get_b() << "\n";

	return 0;
}