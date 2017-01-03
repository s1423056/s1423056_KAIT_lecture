#include <iostream>
#include <cstring>
using namespace std;

const int studentnum = 2;

class StudentList {
	 char name[50];
	 int id;
	 int grade;
public:
	 void set(char *n, int i, int g);
	 void show();
};

class ResultList : public StudentList {
	 char course[100][50];	// �Ȗږ�
	 int credit[100];				// �P�ʐ�
	 char grade[100];			// �]��
	 int number;						// �i�[���Ă���Ȗڐ�
public:
	 ResultList() { number = 0; }
	 void regist(char *title, int crd, char grd);
	 void showResult();
};

void StudentList::set(char *n, int i, int g){
	strcpy(name,n);
	id = i;
	grade = g;
}

void StudentList::show(){
	cout<< "�����F" << name << "\t"
		<< "�w�Дԍ��F" << id << "\t"
		<< "�w�N�F" << grade << endl;
}

void ResultList::regist(char *title, int crd, char grd){
	strcpy(course[number], title);
	credit[number] = crd;
	grade[number] = grd;
	number++;
}

void ResultList::showResult(){
	show();
	for(int i = 0;i<number;i++)
	cout << "�Ȗږ��F" << course[i] << "\t"
	<< "�P�ʐ��F" << credit[i] << "\t"
	<< "�]���F" << grade[i] << endl;
}

int main(){
	int num;
	char t[100];
	int c;
	char g;
	ResultList rlist[studentnum];
	rlist[0].set("��������������",1423190,2);
	rlist[1].set("��������������",1423191,2);
	
	cout << "�w���ꗗ\n";
	for(int i = 0;i<studentnum;i++){
		cout << i+1 << "\t";
		rlist[i].show();
	}
	cout << endl;

	int n = 0;	//�@���ׂďI�����邩�ǂ����̔���
	do{
		cout << "���Ԃ̊w���̃f�[�^����͂��܂����H�F";
		cin >> num;
		cout << "���т���͂��Ă�������" << endl;
		cout << "�I������ꍇ�͉Ȗږ���end�Ɠ��͂��Ă�������" << endl;
		do{
			cout << "�Ȗږ��F";
			cin >> t;
			if(!strcmp(t,"end")) break;
			cout << "�P�ʐ��F";
			cin >> c;
			cout << "�]���F";
			cin >> g;
			rlist[num-1].regist(t,c,g);
		}while(1);

		rlist[num-1].show();
		cout << "���̊w���̃f�[�^����͂��܂���\n";
		cout << "���͂��I�����܂����H" << endl;
		cout << "�I������Ȃ�P���A���s����Ȃ�O����͂��Ă��������F";
		cin >> n;
	}while(!n);

	for(int i = 0; i < studentnum;i++){
		rlist[i].showResult();
		cout << endl;
	}
	return 0;
}