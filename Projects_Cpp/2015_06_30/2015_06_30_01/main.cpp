// 問1
#include <iostream>
using namespace std;

class strtype {
	char *p;
public:
	strtype(char *s);
	strtype(char *s, int n);
	~strtype(){ if(p) delete[] p;}
	char *get() { return p; }
};

strtype::strtype( char *s ){
	int l;
	l = strlen( s )+1;
	p = new char[l];// メモリの動的確保
	if( !p ){	// メモリが確保できてない場合
		cout << "memory error!" << endl;	
		exit( 1 );// エラー終了
	}
	strcpy( p, s );
}

strtype::strtype( char *s, int n ){
	int l = strlen( s )*n +1;
	p = new char[l];//メモリの動的確保
	if( !p ){	// メモリが確保できてない場合
		cout << "memory error!" << endl;
		exit( 1 );	// エラー終了
	}
	*p = '\0';
	for(int i = 0;i < n;i++){
		strcat( p, s );	// n回pにsを連結
	}
}

void show( char *s ){
	cout << s << endl;	//渡された文字列を表示
}

int main()
{
	strtype s1 = strtype( "Good!" );
	strtype s2 = strtype( "Good!",5 );
	cout << "s1:";
	show( s1.get() );	// showにs1の文字列を渡す
	cout << "s2:";
	show( s2.get() );// showにs2の文字列を渡す

	return 0;
}