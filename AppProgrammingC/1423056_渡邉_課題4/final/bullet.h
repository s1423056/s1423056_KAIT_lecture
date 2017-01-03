// bullet.h
// 弾のクラス

#ifndef _BULLET_H
#define _BULLET_H

#include <DxLib.h>

enum BulletColor
{
	WHITE,RED,ORANGE,YELLOW,YELLOWGREEN,
	GREEN,LIGHTBLUE,BLUE,PURPLE,PINK,COLOR_NUM
};

class CBullet
{
private:
	static int GHandle[COLOR_NUM];	// グラフィックハンドル
	float posX, posY;					// 位置
	float velocityX, velocityY;	// 速度
	float accX, accY;					// 加速度
	BulletColor color;					// 色
	bool active;							// 存在フラグ

public:
	// コンストラクタ
	CBullet();
	CBullet( float px, float py, float v, float angle, float aVel, float aAngle, BulletColor c );

	// 画像読み込み
	static void LoadGraphic();

	// 初期化
	void Initialize( float px, float py, float vx, float vy, float ax, float ay, BulletColor c );
	void InitializeA( float px, float py, float v, float angle, BulletColor c );
	void InitializeAA( float px, float py, float v, float angle, float aVel, float aAngle, BulletColor  c );

	
	bool GetActive(){ return active; }

	// 更新
	void Update();

	// 描画
	void Draw();
};

#endif