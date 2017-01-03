#include <iostream>
using namespace std;
#include <stdlib.h>
#include <time.h>
#define TEST_COUNT 1000

class koma{
	int masu;
	int count;
	bool clear;
public:
	koma();
	void move();
	void initialize();
	bool get_clear(){return clear;}
	int get_count(){return count;}
};

koma::koma(){
	masu = 0;
	count = 0;
	clear = false;
}

void koma::initialize(){
	masu = 0;
	count = 0;
	clear = false;
}

void koma::move(){
	int me = rand()%6+1;
	if(20 - masu < me) masu = 20 - (me - (20-masu));
	else masu += me;
	count++;
	if(masu == 20) clear = true;
}

int main(){
	koma k;
	float all_count = 0;
	srand(unsigned int(time(NULL)));

	for(int i = 0;i<TEST_COUNT;i++){
		k.initialize();
		while(!k.get_clear()){
			k.move();
		}
		all_count += k.get_count();
	}

	cout<< "20ƒ}ƒXæ‚ÌƒS[ƒ‹‚É‚½‚Ç‚è’…‚­‚Ì‚É•½‹Ï" << all_count /TEST_COUNT<< 
		"‰ñ‚³‚¢‚±‚ë‚ðU‚è‚Ü‚µ‚½\n";
	return 0;
}