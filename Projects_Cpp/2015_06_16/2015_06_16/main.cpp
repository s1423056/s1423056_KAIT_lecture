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
	 char course[100][50];	// 科目名
	 int credit[100];				// 単位数
	 char grade[100];			// 評価
	 int number;						// 格納してある科目数
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
	cout<< "氏名：" << name << "\t"
		<< "学籍番号：" << id << "\t"
		<< "学年：" << grade << endl;
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
	cout << "科目名：" << course[i] << "\t"
	<< "単位数：" << credit[i] << "\t"
	<< "評価：" << grade[i] << endl;
}

int main(){
	int num;
	char t[100];
	int c;
	char g;
	ResultList rlist[studentnum];
	rlist[0].set("あいうえおかき",1423190,2);
	rlist[1].set("くけこさしすせ",1423191,2);
	
	cout << "学生一覧\n";
	for(int i = 0;i<studentnum;i++){
		cout << i+1 << "\t";
		rlist[i].show();
	}
	cout << endl;

	int n = 0;	//　すべて終了するかどうかの判定
	do{
		cout << "何番の学生のデータを入力しますか？：";
		cin >> num;
		cout << "成績を入力してください" << endl;
		cout << "終了する場合は科目名にendと入力してください" << endl;
		do{
			cout << "科目名：";
			cin >> t;
			if(!strcmp(t,"end")) break;
			cout << "単位数：";
			cin >> c;
			cout << "評価：";
			cin >> g;
			rlist[num-1].regist(t,c,g);
		}while(1);

		rlist[num-1].show();
		cout << "この学生のデータを入力しました\n";
		cout << "入力を終了しますか？" << endl;
		cout << "終了するなら１を、続行するなら０を入力してください：";
		cin >> n;
	}while(!n);

	for(int i = 0; i < studentnum;i++){
		rlist[i].showResult();
		cout << endl;
	}
	return 0;
}