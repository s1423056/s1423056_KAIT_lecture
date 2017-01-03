// bullet.cpp
// �e�̃N���X

#include "bullet.h"
#include <math.h>

int CBullet::GHandle[BulletColor::COLOR_NUM];

// �摜�ǂݍ���
void CBullet::LoadGraphic()
{
	int Graph = LoadGraph( "bullets.png" );
	for( int i = 0; i < BulletColor::COLOR_NUM; i++){
		GHandle[i] = DerivationGraph( i*32, 32, 32, 32, Graph );
	}	
}

// �R���X�g���N�^
CBullet::CBullet()
{
	posX = posY = 0.0f;
	velocityX = velocityY = 0.0f;
	accX = accY = 0.0f;
	color = WHITE;
	active = false;
}

CBullet::CBullet( float px, float py, float v, float angle, float aVal, float aAngle, BulletColor c )
{
	InitializeAA( px, py, v, angle, aVal, aAngle, c );
}

// ������
void CBullet::Initialize( float px, float py, float vx, float vy, float ax, float ay, BulletColor c )
{
	posX = px, posY = py, velocityX = vx, velocityY = vy, accX = ax, accY = ay, color = c;
	active = true;
}

void CBullet::InitializeA( float px, float py, float v, float angle, BulletColor c )
{
	posX = px, posY = py, color = c;
	velocityX = cos(angle*3.14159f/180.0f)*v;
	velocityY = sin(angle*3.14159f/180.0f)*v;
	active = true;
}

void CBullet::InitializeAA( float px, float py, float v, float angle, float aVel, float aAngle, BulletColor  c )
{
	posX = px, posY = py, color = c;
	velocityX = cos(angle*3.14159f/180.0f)*v;
	velocityY = sin(angle*3.14159f/180.0f)*v;
	accX = cos(aAngle*3.14159f/180.0f)*aVel;
	accY = sin(aAngle*3.14159f/180.0f)*aVel;
	active = true;
}

// �X�V
void CBullet::Update()
{
	posX += velocityX;
	posY += velocityY;
	velocityX += accX;
	velocityY += accY;
	if( posX > 700 || posX < -60 || posY > 530 || posY < - 60 ) active = false;
}

// �`��
void CBullet::Draw()
{
	DrawRotaGraph( posX, posY, 1.0f, 0.0f, GHandle[color], TRUE );
}