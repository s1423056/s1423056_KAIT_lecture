#include <iostream>
using namespace std;

class StudentList{
	char name[50];
	int id;
	int grade;
public:
	void set(char *n, int i, int g);
	void show();
};

void StudentList::set(char *n, int i, int g){
	strcpy(name,n);
	id = i;
	grade = g;
}

void StudentList::show(){
	cout << "�����F" << name 
		<< "\t" << "�w�Дԍ��F" << id 
		<< "\t" << "�w�N�F" << grade << "\n";
}

int main(){
	char n[50];
	int id;
	int g;
	StudentList list[5];
	StudentList *p;
	p = list;
	for(int i = 0; i < 5; i++){
		cout << i+1 <<"�l�ڂ̃f�[�^����͂��܂�\n";
		cout << "���O����͂��Ă��������F";
		cin >> n;
		cout << "�w�Дԍ�����͂��Ă��������F";
		cin >> id;
		cout << "�w�N����͂��Ă��������F";
		cin >> g;
		p->set(n,id,g);
		p++;
	}

	p = list;
	for(int i = 0; i < 5; i++){
		cout << i+1 << "\t";
		p -> show();
		p++;
	}

	return 0;
}