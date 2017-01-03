// SeatReserveSystem.h
// 座席予約管理システムのクラス
// 作成日：2016/6/7
// 作成者：渡邉 翔

#ifndef _SEATRESERVESYSTEM_H
#define _SEATRESERVESYSTEM_H

#include "SeatManagar.h"
#include "FileManager.h"
#include "UI.h"

class CSeatReserveSystem{
private:
	CSeatManager seatManager;	// 座席管理
	CFileManager fileManager;		// ファイル入出力管理
	CUserInterface UI;					// ユーザー入力
	CConverter converter;				// stringをSEAT_NUMに変換するクラス

	// 予約実行
	void Reserve();

	// キャンセル実行
	void Cansel();
		
	// ファイルを読み込んで状態を更新
	void Update();

public:
	// コンストラクタ
	CSeatReserveSystem();

	// 実行
	void Run();
	

};

#endif