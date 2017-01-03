// 課題４

#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

#define CARDMAX 12

enum suit { SPADE, HEART, CLUB, DIAMOND };

class PCard {
	 enum suit suit;
	int number;
public:
	void set(enum suit st, int nm) {
		suit = st;
		number = nm;
	}

	 void show();
};

void PCard::show() {
	 switch(suit) {
	case SPADE:
		cout << "スペードの";
		break;
	case HEART:
		cout << "ハートの";
		break;
	case CLUB:
		cout << "クラブの";
		break;
	case DIAMOND:
		cout << "ダイヤの";
		break;
	}
	cout << number << "\n";
}

void changeCard(PCard &c1, PCard &c2){
	PCard tmp;
	tmp = c1;
	c1 = c2;
	c2 = tmp;
}

int main(){
	PCard card[CARDMAX];
	int i;
	for(i = 0;i < 4;i++){
		card[i].set(SPADE,i+1);
		card[i+4].set(HEART,i+1);
		card[i+8].set(CLUB,i+1);
	}

	for(i = 0;i<CARDMAX;i++){
		card[i].show();
	}

	cout << "\nシャッフルします\n"<< endl;

	srand(time(NULL));
	for(i = 0;i < 10000; i++){
		int a = rand() % CARDMAX;
		int b = rand() % CARDMAX;
		changeCard(card[a], card[b]);
	}

	for(i = 0;i<CARDMAX;i++){
		card[i].show();
	}

	return 0;
}