// bullet.h
// �e�̃N���X

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
	static int GHandle[COLOR_NUM];	// �O���t�B�b�N�n���h��
	float posX, posY;					// �ʒu
	float velocityX, velocityY;	// ���x
	float accX, accY;					// �����x
	BulletColor color;					// �F
	bool active;							// ���݃t���O

public:
	// �R���X�g���N�^
	CBullet();
	CBullet( float px, float py, float v, float angle, float aVel, float aAngle, BulletColor c );

	// �摜�ǂݍ���
	static void LoadGraphic();

	// ������
	void Initialize( float px, float py, float vx, float vy, float ax, float ay, BulletColor c );
	void InitializeA( float px, float py, float v, float angle, BulletColor c );
	void InitializeAA( float px, float py, float v, float angle, float aVel, float aAngle, BulletColor  c );

	
	bool GetActive(){ return active; }

	// �X�V
	void Update();

	// �`��
	void Draw();
};

#endif