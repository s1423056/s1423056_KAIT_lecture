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
	cout << "氏名：" << name 
		<< "\t" << "学籍番号：" << id 
		<< "\t" << "学年：" << grade << "\n";
}

int main(){
	char n[50];
	int id;
	int g;
	StudentList list[5];
	StudentList *p;
	p = list;
	for(int i = 0; i < 5; i++){
		cout << i+1 <<"人目のデータを入力します\n";
		cout << "名前を入力してください：";
		cin >> n;
		cout << "学籍番号を入力してください：";
		cin >> id;
		cout << "学年を入力してください：";
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