// 問４カードクラスの演算子オーバーロード

#include <iostream>
#include <time.h>		// 乱数生成のため
#include <stdlib.h>		// メモリリーク検出のため
#include <crtdbg.h>	// メモリリーク検出のため

using namespace std;	// いつもの

#define _CRTDBG_MAP_ALLOC	// メモリリーク検出のため
#define new ::new( _NORMAL_BLOCK, __FILE__, __LINE__ )		// メモリリーク検出のため

#define MAX_NUM 100

class Cards {
	char *name[MAX_NUM];
	int number;

public:
	// コンストラクタ
	Cards() { number = 0; }

	// コピーコンストラクタ
	Cards( const Cards &ob );

	// デストラクタ
	~Cards() {
		// 含まれているカードをすべてdelete
		for (int i = 0; i < number; i++)
			delete [] name[i];
	}

	// カード追加
	void add( char *str);

	// strという名前のカードを削除
	int del( char *str );

	// nに対応するカードを削除
	 int del( int n );

	// カードの数を0にする
	void cls();

	// 含まれるカードをすべて表示
	void show();

	// ランダムに並べ替え
	void shuffle();

	// カード名の昇順に並べかえ
	void sort();

	// 配列の添え字 n 番から m 枚カードを取り出す
	Cards draw( int n, int m );

	Cards operator+( Cards &ob );		// カード同士を足し合わせる
	Cards &operator=( Cards &ob );		// 自身のオブジェクトにobを移す
	Cards &operator+=( Cards &ob );	// 自身のオブジェクトにobを足しこむ
	Cards operator<<( int n );				// 先頭からn枚のカードを抜き出す
	char *operator[]( int i );					// 添え字演算子でカード名を取り出す
};

// ================================================================
// コピーコンストラクタ
// ================================================================
Cards::Cards( const Cards &ob )
{
	number = 0;
	for(int i = 0; i < ob.number; i++)
	{
		this -> add( ob.name[i] );
	}
}

// ================================================================
// カードを追加
// ================================================================
void Cards::add( char *str )
{
	name[number] = new char[strlen(str)+1];
	strcpy( name[number], str );
	number++;
}

// ================================================================
// strという名前のカードを削除
// ================================================================
int Cards::del( char *str )
{
	int i;
	for(i = 0; i < number; i++)
	{
		if( !strcmp( name[i], str ) )
		{
			delete[] name[i];
			while(i+1 < number)
			{
				name[i] = name[i+1];
				i++;
			}
			number--;
			return 1;
		}
	}
	return 0;
}

// ================================================================
// nに対応するカードを削除
// ================================================================
int Cards::del( int n )
{
	int i;
	if( n < number ){
		delete[] name[n];
		i = n;
		while(i+1 < number){
			name[i] = name[i+1];
			i++;
		}
		number--;
		return 1;
	}
	return 0;
}

// ================================================================
// カードの数を0枚に
// ================================================================
void Cards::cls()
{
	for( int i = 0;i < number; i++ )
	{
		delete[] name[i];	// [i]番のchar型配列をdelete（配列のdeleteは[]をつける）
	}
	number = 0;
}

// ================================================================
// 含まれているカードをすべて表示
// ================================================================
void Cards::show()
{
	for( int i = 0; i < number; i++ )	// numberの数だけカードを表示
	{
		cout << name[i] << endl;
	}
}

// ================================================================
// ランダムに並べかえ
// ================================================================
void Cards::shuffle()
{
	char *temp;
	srand( (unsigned int)time( NULL ) );
	for( int i = 0 ;i < 1000; i++ )
	{
		int n1 = rand() % number;
		int n2 = rand() % number;
		temp = name[n1];
		name[n1] = name[n2];
		name[n2] = temp;
	}
}

// ================================================================
// カード名を昇順に並べ替え
// ================================================================
void Cards::sort()
{
	// 上から順に並べ替える
	for(int i = 0; i < number-1;i++)
	{
		for(int j = i+1;j < number; j++)
		{
			if(name[i][0] > name[j][0])
			{
				char* temp = name[i];
				name[i] = name[j];
				name[j] = temp;
			}
			else if(name[i][0] == name[j][0]){	// 文字が同じ場合
				// 違う文字がでるまで1文字ずつ比較
				for( int n = 1;n < MAX_NUM;n++)
				{
					if(name[i][n] != name[i][n])
					{
						char* temp = name[i];
						name[i] = name[j];
						name[j] = temp;
						break;
					}
				}
			}
		}
	}
}

// ================================================================
// 配列の添え字n番からm枚カードを取り出す
// ================================================================
Cards Cards::draw( int n, int m = 1 )
{
	Cards temp;

	if( n>= 0 && n+m <= number )
	{
		for( int i = 0; i < m; i++ )
		{
			temp.add(name[n]);
			this -> del(n);
		}
	}
	return temp;
}

// ================================================================
// カード同士を足し合わせる
// ================================================================
Cards Cards::operator+( Cards &ob )
{
	Cards tmp;
	for( int i = 0; i < this -> number; i++ )
	{
		tmp.add( this ->name[i] );
	}
	for( int i = 0; i < ob.number; i++ )
	{
		tmp.add( ob.name[i] );
	}
	return tmp;
}

// ================================================================
// 自身のオブジェクトにobを移す
// ================================================================
Cards &Cards::operator=( Cards &ob )
{
	this -> cls();	// もともと含まれていたカードをすべて消す
	// obに含まれているカードをすべて左オペランドに追加
	for( int i = 0; i < ob.number; i++ )
	{
		this -> add( ob.name[i] );
	}
	ob.cls();	// obに含まれているカードをすべて消す
	return *this;
}

// ================================================================
// 自身のオブジェクトにobを足しこむ
// ================================================================
Cards &Cards::operator+=( Cards &ob )
{
	// obに含まれるカードをすべて左のオペランドに追加する
	for( int i = 0; i < ob.number; i++ )
	{
		this -> add(ob.name[i]);
	}
	ob.cls();	// obに含まれるカードをすべて消す
	return *this;
}

// ================================================================
// 先頭からn枚のカードを抜きだす
// ================================================================
Cards Cards::operator<< ( int n )
{
	Cards tmp;

	// 先頭からn枚のカードをtmpに追加
	for( int i = 0; i < n; i++)
	{
		tmp.add( this -> name[i] );
	}

	// 左オペランドの残りのカードを先頭に詰める
	for( int i = 0; i < n; i++)
	{
		delete[] this -> name[i];
	}
	for( int i = n; i < number; i++ )
	{
		this -> name[i -n] = this -> name[i];
	}

	// 後ろからn枚を消す
	for( int i = number-1; i >= number - n; i--)
	{
		name[i] = NULL;
	}

	// 枚数を合わせる
	this -> number -= n;

	return tmp;
}

// ================================================================
// 添え字演算子でカード名を取り出す
// ================================================================
char *Cards::operator[]( int i )
{
	if(i >= 0 && i < number )
		return name[i];
	else
		return "error";
}

// ================================================================
// メイン関数
// ================================================================
int main() {

	_CrtSetDbgFlag( _CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF );

	Cards deck, hand;
	deck.add("Manabarbs");
	deck.add("Birds of Paradise");
	deck.add("Shivan Dragon");
	deck.add("Nightmare");
	deck.add("Royal Assassin");
	deck.add("Clone");
	deck.add("Mahamoti Djinn");
	deck.add("Hypnotic Specter");

	cout << "山札を表示\n";
	deck.show();

	cout << "\nシャッフル\n";
	deck.shuffle();
	deck.show();

	cout << "\nソート\n";
	deck.sort();
	deck.show();

	cout << "\n山札の6枚目のカードを手札に\n";
	hand = deck.draw(5);

	cout << "\n山札の3枚目から2枚を手札に\n";
	hand += deck.draw(2, 2);

	cout << "\n山札を表示\n";
	deck.show();

	cout << "\nfor文を使って手札を3枚表示\n";
	for (int i = 0; i < 3; i++)
		cout << hand[i] << "\n";

	return 0;

}