#include <iostream>
using namespace std;

int main() {
	int i, n;
	char **strlist;
	char buf[255]; // •¶š—ñ‚ÍÅ‘å‚Å256•¶š‚Æ‚·‚é

	cout << "•¶š—ñ‚Ì”:";
	cin >> n;
	strlist = new char*[n];
	if (!strlist) {
		cout << "ƒƒ‚ƒŠ‚ªŠm•Û‚Å‚«‚Ü‚¹‚ñ\n";
		return 1;
	}

	cout << "•¶š—ñ‚Ì“ü—Í\n";
	for (i = 0; i < n; i++) {
		cout << i+1 <<"‚Â–Ú:";
		cin >> buf;
		strlist[i] = new char[255];
		if (!strlist[i]) {
			cout << "ƒƒ‚ƒŠ‚ª‘«‚è‚Ü‚¹‚ñ\n";
			return 1;
		}
		strcpy(strlist[i], buf);
	}

	cout << "•¶š—ñ‚Ìo—Í\n";
	for (i = 0; i < n; i++) {
		cout << i+1 <<"‚Â–Ú:";
		cout << strlist[i] <<"\n";
	}
	for(int i = 0;i<n;i++) delete[] strlist[i];
	delete[] strlist;
	return 0;
}