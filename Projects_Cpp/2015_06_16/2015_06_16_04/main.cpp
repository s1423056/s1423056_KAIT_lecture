#include <iostream>
using namespace std;

int main() {
	int i, n;
	char **strlist;
	char buf[255]; // ������͍ő��256�����Ƃ���

	cout << "������̐�:";
	cin >> n;
	strlist = new char*[n];
	if (!strlist) {
		cout << "���������m�ۂł��܂���\n";
		return 1;
	}

	cout << "������̓���\n";
	for (i = 0; i < n; i++) {
		cout << i+1 <<"��:";
		cin >> buf;
		strlist[i] = new char[255];
		if (!strlist[i]) {
			cout << "������������܂���\n";
			return 1;
		}
		strcpy(strlist[i], buf);
	}

	cout << "������̏o��\n";
	for (i = 0; i < n; i++) {
		cout << i+1 <<"��:";
		cout << strlist[i] <<"\n";
	}
	for(int i = 0;i<n;i++) delete[] strlist[i];
	delete[] strlist;
	return 0;
}