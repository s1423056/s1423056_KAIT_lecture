#include <iostream>
using namespace std;

#define SIZE 10

// 文字を保存するstackクラスを宣言する
class stack{
	char stck[SIZE];			// スタック領域を確保する
	int tos;							// スタック先頭の索引
public:
	void init();					// スタックを初期化する
	void push(char ch);		// スタックに文字をプッシュする
	char pop();					// スタックから文字をポップする
	void dup();					// トップを複製する
	char peek();				// 値を読み出す
	void swap();				// 上2つのアイテムを入れ替え
	void rot_r();					// 右回転
	void rot_l();					// 左回転
};

// スタックを初期化する
void stack::init(){
	tos = 0;
}

// 文字をプッシュする
void stack::push(char ch){
	if(tos == SIZE){
		cout << "スタックはいっぱいです";
		return;
	}
	stck[tos] = ch;
	tos++;
}

// 文字をポップする
char stack::pop(){
	if(tos == 0){
		cout << "スタックは空です";
		return 0;
	}
	tos--;
	return stck[tos];
}

void stack::dup(){
	stck[tos + 1] = stck[tos];
	return;
}

char stack::peek(){
	return stck[tos];
}

void stack::swap(){
	char tmp = stck[tos];
	stck[tos] = stck[tos-1];
	stck[tos -1] = tmp;
	return;
}

void rot_r(){

};

int main(){
	stack s1;
	int i;
}