#include <iostream>
using namespace std;

int main(){
	char name[80];
	int score;
	char rate;

	cout << "名前を入力してください：";
	cin >> name;
	cout << "点数を入力してください：";
	cin >> score;

	if(score >100 || score < 0) rate = 'X';	// 100以上0以下でX
	else if(score < 60) rate = 'E';	// 60以下でE
	else if(score < 70) rate = 'C';	// 70以下でC
	else if(score < 80) rate = 'B';	// 80以下でB
	else if(score < 90) rate = 'A';	// 90以下でA
	else rate = 'S';							// それ以外ならS

	cout << name<<"さんの評価は"<<rate<<"です。\n";

	return 0;
}