#include <iostream>
#include <fstream> // ファイル入出力に必要
using namespace std;

int main() {
	char header[54]; // ヘッダ格納用配列
	char inputlen[100];
	char outputlen[100];
	cout << "入力ファイル名：";
	cin >> inputlen;
	cout << "出力ファイル名：";
	cin >> outputlen;
	ifstream fin( inputlen , ios::in | ios::binary ); // バイナリモードで入力ファイルをオープン
	if(!fin){
		cout << "input file open error!" << endl; 
		return 1;
	}

	ofstream fout( outputlen, ios::out | ios::binary ); // バイナリモードで出力ファイルをオープン
	if(!fout){
		cout << "output file open error!" << endl;
		return 1;
	}

	fin.read(header, 54); // ヘッダ読み込み
	fout.write(header, 54); // ヘッダ書き込み

	char a; // データを読み込むためのバッファ

	while(!fin.eof()) { // 入力ファイルの終わりまで繰り返す
		fin.get(a);// 入力ストリームから 1 バイトデータ読み込み
		a = ~a;// ビット反転
		fout.put(a);// 出力ストリームにビット反転したデータを書き込み
	}

	fin.close();
	fout.close();

	return 0;
}