#include <iostream>
using namespace std;

int main(){
	char name[80];
	int score;
	char rate;

	cout << "���O����͂��Ă��������F";
	cin >> name;
	cout << "�_������͂��Ă��������F";
	cin >> score;

	if(score >100 || score < 0) rate = 'X';	// 100�ȏ�0�ȉ���X
	else if(score < 60) rate = 'E';	// 60�ȉ���E
	else if(score < 70) rate = 'C';	// 70�ȉ���C
	else if(score < 80) rate = 'B';	// 80�ȉ���B
	else if(score < 90) rate = 'A';	// 90�ȉ���A
	else rate = 'S';							// ����ȊO�Ȃ�S

	cout << name<<"����̕]����"<<rate<<"�ł��B\n";

	return 0;
}