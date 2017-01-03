// ‰Û‘è1

#include <iostream>
using namespace std;

void f(int &n) {
	n = n * 2;
}

int main() {
	int i = 10;
	cout << "i = " << i << "\n";
	f(i);
	cout << "i = " << i << "\n";
	return 0;
}