#include <iostream>
using namespace std;

union bits{
	bits(int n);
	void show_bits();
	int i;
	unsigned char c[sizeof(int)];
};

bits::bits(int n){
	i = n;
}

void bits::show_bits(){
	int i,j;
	for(j = sizeof(int)-1; j>=0; j--){
		cout<< "バイト単位のビットパターン"<<j<<": ";
		for(i = 128; i; i >>= 1)
			if(i & c[j])cout << "1";
			else cout << "0";
			cout << "\n";
	}
}

int main(){
	bits ob(123456);
	ob.show_bits();
	return 0;
}