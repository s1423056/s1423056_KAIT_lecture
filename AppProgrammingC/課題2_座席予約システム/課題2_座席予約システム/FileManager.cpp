// FileManager.cpp
// ファイル入出力管理を行うクラス
// 作成日：2016/6/7
// 作成者：渡邉 翔

#include "FileManager.h"

// コンストラクタ
CFileManager::CFileManager( CConverter* converter ) : converter( converter )
{}

// 拡張子を消したファイル名を取得
string CFileManager::ExPathWithoutExt( string &filename )
{
	string seatStr;	// string型座席番号
	string::size_type pos;	// 文字列中の位置
	if( ( pos = filename.find_last_of( "." ) ) == string::npos )
		return filename;

	return filename.substr( 0, pos );
}

// ファイル入力
bool CFileManager::ImportFile( const string filename, CSeatManager* seatM )
{
	bool flag = false;	// 成功時にtrueに置き換える
	string seatNum = filename;	// 拡張子なしのファイル名にするための文字列
	ifs.open( filename );

	if( ifs ){	// ファイルを開けた	
		string seatStr = ExPathWithoutExt( seatNum );	// 拡張子を消したファイル名に
		SEAT_NUM seatNum = converter -> convert( seatStr );	// ファイル名から座席番号に
		seatM -> Reserve( seatNum );	// ファイルがあるということは座席予約済みである
		flag = true;
	}

	ifs.close();	// 閉じる
	return flag;
}

// ファイル出力
bool CFileManager::ExportFile( const string filename, UserData data )
{
	bool flag = false;	// 成功時にtrueに置き換える
	string str = data.name;
	ofs.open( filename, ios::out );
	if( ofs ){	// ファイルがある場合予約済み	
		// ファイルが存在しない場合
		ofs << str << endl;	// ファイルを作成してユーザー名を書き込む
		if( !ofs.fail() )flag = true;
	}
	ofs.close();	// 閉じる
	return flag;
}
