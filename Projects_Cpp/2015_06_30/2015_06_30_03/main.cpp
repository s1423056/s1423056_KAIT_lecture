// 問3
#include <iostream>
using namespace std;

class strtype {
	char *p;
public:
	strtype(char *s = NULL, int n = 1); // デフォルト引数を利用
	strtype( const strtype &o ); // コピーコンストラクタ
	~strtype() { delete [] p; }
	char *get() { return p; }
};

strtype::strtype( char *s, int n){
	int l = strlen(s)*n+1;
	p = new char[l];
	if(!p){
		cout << "memory error!" << endl;
		exit(1);
	}
	*p = '\0';
	for(int i = 0;i<n;i++)strcat(p,s);
}

strtype::strtype( const strtype &o ){
	int l;
	l = strlen(o.p)+1;
	
	p = new char[l];
	if(!p){
		cout << "memory error!" << endl;
		exit(1);
	}
	strcpy(p, o.p);
}

int ccount( strtype x, char c )
{
	// 文字 c の数を返す
	int count = 0;
	int length = strlen(x.get());
	char *str = x.get();
	for(int i = 0; i < length; i++){
		if(*str == c)count++;
		str++;
	}
	return count;
}

int main(){
	char ch1[100],ch2[100];
	int c;
	char a;
	cout << "文字列s1を設定します。"<< endl;
	cout << "文字列を入力してください。：";
	cin >> ch1;
	cout << "繰り返し文字列s2を設定します。"<< endl;
	cout << "文字列を入力してください。：";
	cin >> ch2;
	cout << "繰り返し回数を入力してください。：";
	cin >> c;
	cout << "文字列s1とs2に含まれるある文字の数を数えます。" << endl;
	cout << "文字を入力してください：";
	cin >> a;
	strtype s1 = strtype( ch1 );
	strtype s2 = strtype( ch2, c );
	cout << "s1 の" << a << "の数：" << ccount( s1,a )<< endl;
	cout << "s2 の" << a << "の数：" << ccount( s2,a )<< endl;
	cout << "s1：" << s1.get() << endl;
	cout << "s2：" << s2.get() << endl;
	return 0;
}