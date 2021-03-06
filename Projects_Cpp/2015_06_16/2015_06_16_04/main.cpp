#include <iostream>
using namespace std;

int main() {
	int i, n;
	char **strlist;
	char buf[255]; // 文字列は最大で256文字とする

	cout << "文字列の数:";
	cin >> n;
	strlist = new char*[n];
	if (!strlist) {
		cout << "メモリが確保できません\n";
		return 1;
	}

	cout << "文字列の入力\n";
	for (i = 0; i < n; i++) {
		cout << i+1 <<"つ目:";
		cin >> buf;
		strlist[i] = new char[255];
		if (!strlist[i]) {
			cout << "メモリが足りません\n";
			return 1;
		}
		strcpy(strlist[i], buf);
	}

	cout << "文字列の出力\n";
	for (i = 0; i < n; i++) {
		cout << i+1 <<"つ目:";
		cout << strlist[i] <<"\n";
	}
	for(int i = 0;i<n;i++) delete[] strlist[i];
	delete[] strlist;
	return 0;
}