#include <iostream>
using namespace std;

class StudentList{
	char name[50];
public:
	void set(char *n){strcpy(name,n);}
	void show(){cout << name << "\n";}
};

int main(){
	StudentList s1,s2;
	StudentList *ptr;
	char n[50];

	ptr = &s1;
	cout << "1�l�ڂ̃f�[�^����͂��܂�\n";
	cout << "���O����͂��Ă��������F";
	cin >> n;
	ptr -> set(n);

	ptr = &s2;
	cout << "2�l�ڂ̃f�[�^����͂��܂�\n";
	cout << "���O����͂��Ă��������F";
	cin >> n;
	ptr -> set(n);

	ptr = &s1;
	cout << 1 << "\t";
	ptr -> show();

	ptr = &s2;
	cout << 2 << "\t";
	ptr -> show();
	cout << "\n";

	return 0;
}