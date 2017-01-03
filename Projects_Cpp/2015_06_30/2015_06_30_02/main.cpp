// 問2
#include <iostream>
using namespace std;

class strtype {
	char *p;
public:
	strtype( char *s );
	strtype( char *s, int n );
	strtype( const strtype &o ); // コピーコンストラクタ
	~strtype() { if(p) delete [] p; }
	char *get() { return p; }
};

strtype::strtype( char *s ){
	int l = strlen(s)+1;
	p = new char[l];
	if(!p){
		cout << "memory error!" << endl;
		exit(1);
	}
	strcpy(p,s);
}

strtype::strtype( char *s, int n ){
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

void show( strtype s ){
	char *c;
	c = s.get();
	cout << c << endl;
}

int main()
{
	strtype s1( "Good!" );
	strtype s2( "Good!", 5 );
	cout << "s1 の o の数: " << ccount( s1, 'o' ) << "\n";
	cout << "s2 の o の数: " << ccount( s2, 'o' ) << "\n";
	show(s1);
	show(s2);
}