// charactor.h
// キャラクタのクラス

#ifndef _CHARACTOR_H
#define _CHARACTOR_H

#include <tchar.h>
#include <d3dx9.h>
#include <list>
using namespace std;

enum TYPE{
	TOUGH,
	QUICK,
	CHARGE,
	LUCKY,
	NORMAL
};

enum STATUS{
	HP, SPEED, CHARGEMAX, LUCK, NONE
};

class CCharactor
{
private:
	TCHAR name[32];	// 名前
	int hp;						// 体力
	int speed;				// 素早さ
	int chargeMAX;		// タメMAX
	int luck;					// 運

	bool showStatus;		// ステータスを表示するかどうか
	bool activeEffectA;	// 創造効果Aが開始されたかどうか
	bool activeEffectB;	// 創造効果Bが開始されたかどうか
	bool endEffectA;		// 創造効果Aが終了したかどうか
	bool endEffectB;		// 創造効果Bが終了したかどうか

	int GHandle;	// グラフィックハンドル
	int alpha;			// 不透明度
	int posX, posY;	// 魔方陣表示位置
	double angle;	// 回転角

	// それぞれのタイプ毎でパラメータ割振り
	void SetTough();
	void SetQuick();
	void SetCharge();
	void SetLuck();
	void SetRandom();

public:
	// コンストラクタ
	CCharactor();

	// キャラクタ初期化
	void Initialize( TYPE t );

	// 更新
	void Update();

	// 描画
	void Draw();

	// 名前設定
	TCHAR* GetName(){ return name; }

	// ステータス表示切替
	void ToggleShowStatus(){ showStatus = !showStatus; }
	void SetShowStatus( bool b ){ showStatus = b; }
	bool GetShowStatus(){ return showStatus; }

	bool GetActiveEffectA(){ return activeEffectA; }
	bool GetActiveEffectB(){ return activeEffectB; }

	void SetActiveEffectB( bool b) { activeEffectB = b; }

	bool GetEndEffectA(){ return endEffectA; }
	bool GetEndEffectB(){ return endEffectB; }

	void SetEndEffectA(bool b){endEffectA = b;}
	void SetEndEffectB(bool b){endEffectB = b;}

	// ステータス取得
	int GetHP(){return hp; }
	int GetSpeed(){ return speed; }
	int GetChargeMAX(){ return chargeMAX; }
	int GetLuck(){ return luck;}

	// ステータス設定
	void SetHP( int val ){ hp = val; }
	void SetSpeed( int val ){ speed = val; }
	void SetChargeMAX( int val ){ chargeMAX = val; }
	void SetLuck( int val ){ luck = val; }

	// 一番数値の高いステータスを返す
	STATUS GetMaxStatus(){
		STATUS st = NONE;
		if( hp > speed && hp > chargeMAX && hp > luck ) st = HP;
		if( speed > hp && speed > chargeMAX && speed > luck) st = SPEED;
		if( chargeMAX > hp && chargeMAX > speed && chargeMAX > luck ) st = CHARGEMAX;
		if( luck > hp && luck > speed && luck > chargeMAX ) st = LUCK;
			return st;
	}

	// 位置取得
	int GetPosX(){ return posX; }
	int GetPosY(){ return posY; }

	// 角度取得
	float GetAngle(){ return angle; }

	// ステータス加算
	void AddHP( int val ){ hp += val; }
	void AddSpeed( int val ){ speed += val; }
	void AddChargeMAX( int val ){ chargeMAX += val; }
	void AddLuck( int val ){ luck += val; }

	// 創造効果
	void EffectA(){ activeEffectA = true; }
	void EffectB(){ activeEffectB = true; }
};

#endif