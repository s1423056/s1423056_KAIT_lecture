// FileManager.h
// 外部ファイルを扱うクラス
// 作成日：2016/5/19
// 作成者：渡邉 翔

#ifndef _FILEMANAGER_H
#define _FILEMANAGER_H

#include "SeatManagar.h"
#include "UserInput.h"
#include <fstream>
#include <iostream>
using namespace std;

class CFileManager
{
private:
	ifstream ifs;		// ファイル入力ストリーム
	ofstream ofs;	// ファイル出力ストリーム
	CConverter* converter;	// string型からSEAT_NUMに変換するクラスのポインタ
	string ExPathWithoutExt( string &filename );	// 拡張子を消したファイル名を取得
	void importLoop( string filenameHead );	// ものぐさ関数

public:
	// コンストラクタ
	CFileManager( CConverter* converter );

	// ファイル読み込み
	// filename：ファイル名
	bool ImportFile( const string filename, CSeatManager* seatM );

	// ファイル読み込み
	string ImportFile( const string filename ){
		string str, filenameStr;
		filenameStr = filename + ".txt";
		ifs.open( filenameStr );
		if( ifs.fail() )
			cerr << "失敗" << endl;
		getline( ifs, str );
		return str;	
	}

	// ファイル書き出し
	// filename：ファイル名(座席番号)
	bool ExportFile( const string filename, UserData data );

};

#endif