// 問４カードクラスの演算子オーバーロード

#include <iostream>
#include <stdlib.h>		// メモリリーク検出のため
#include <crtdbg.h>	// メモリリーク検出のため


using namespace std;

#define _CRTDBG_MAP_ALLOC	// メモリリーク検出のため
#define new ::new( _NORMAL_BLOCK, __FILE__, __LINE__ )	// メモリリーク検出のため
#define MAX_NUM 100

class Cards {
	char *name[MAX_NUM];
	int number;

public:
	// コンストラクタ
	Cards() { number = 0; }

	// コピーコンストラクタ
	Cards(const Cards &ob);

	// デストラクタ
	~Cards() {
		// 含まれているカードをすべてdelete
		for (int i = 0; i < number; i++)
			delete [] name[i];
	}

	// カード追加
	void add(char *str);

	// strという名前のカードを削除
	//int del(char *str);

	// nに対応するカードを削除
	// int del(int n);

	// カードの数を0にする
	void cls();

	// 含まれるカードをすべて表示
	void show();
	Cards operator+(Cards &ob);			// カード同士を足し合わせる
	Cards &operator=(Cards &ob);		// 自身のオブジェクトにobを移す
	Cards &operator+=(Cards &ob);		// 自身のオブジェクトにobを足しこむ
	Cards operator<<(int n);				// 先頭からn枚のカードを抜き出す
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
Cards &Cards::operator+=(Cards &ob)
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
Cards Cards::operator<< (int n)
{
	Cards tmp;
	// 左オペランドに含まれている先頭からn枚のカードをtmpに追加
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

	// 左オペランドの後ろからn枚を消す
	for( int i = number-1; i >= number - n; i--)
	{
		name[i] = NULL;
	}

	// 左オペランドの枚数を合わせる
	this -> number -= n;

	return tmp;
}

// ================================================================
// メイン関数
// ================================================================
int main() {

	_CrtSetDbgFlag( _CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF );

	Cards deck, hand, discard, temp;
	deck.add("銅貨");
	deck.add("市場");
	deck.add("銀貨");
	deck.add("礼拝堂");
	deck.add("屋敷");
	deck.add("金貨");
	hand.add("銀貨");
	hand.add("地下貯蔵庫");

	cout << "山札↓\n";
	deck.show();

	cout << "\n手札↓\n";
	hand.show();

	cout << "\ntemp=山札+手札\n";
	temp = deck + hand;

	cout << "\ntemp↓\n";
	temp.show();

	cout << "\n山札から2枚手札に加える\n";
	hand += deck << 2;

	cout << "\n山札↓\n";
	deck.show();

	cout << "\n手札↓\n";
	hand.show();

	cout << "\n手札すべてを捨て札に\n";
	discard = hand;
	hand.cls();

	cout << "\n手札↓\n";
	hand.show();

	cout << "\n捨て札↓\n";
	discard.show();

	return 0;
}