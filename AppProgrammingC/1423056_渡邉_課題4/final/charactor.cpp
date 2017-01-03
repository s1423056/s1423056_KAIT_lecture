// charactor.cpp
// キャラクターのクラス

#include "charactor.h"
#include <DxLib.h>


// コンストラクタ
CCharactor::CCharactor()
{
	hp = 1;
	speed = 0;
	chargeMAX = 0;
	luck = 0;
	showStatus = true;

	alpha = 0;
	activeEffectA = false;
	activeEffectB = false;
	endEffectA = false;
	endEffectB = false;

	posX = 0;
	posY = 0;
	angle = 0.0;
}


// タイプ別パラメータ割振り
void CCharactor::SetTough()
{
	for( int i = 0; i < 39; i++ ){
		int r = GetRand(5);
		switch( r ){
			case 0:
			case 1:
			case 2: hp++; break;
			case 3: speed++; break;
			case 4: chargeMAX++; break;
			case 5: luck++; break;
			default: hp++;
		}
	}
}

void CCharactor::SetQuick()
{
	for( int i = 0; i < 39; i++ ){
		int r = GetRand(5);
		switch( r ){
			case 0: hp++; break;
			case 1:
			case 2: 
			case 3: speed++; break;
			case 4: chargeMAX++; break;
			case 5: luck++; break;
			default: speed++;
		}
	}
}

void CCharactor::SetCharge()
{
	for( int i = 0; i < 39; i++ ){
		int r = GetRand(5);
		switch( r ){
			case 0: hp++; break;
			case 1: speed++; break;
			case 2: 
			case 3: 
			case 4: chargeMAX++; break;
			case 5: luck++; break;
			default: chargeMAX++;
		}
	}
}

void CCharactor::SetLuck()
{
	for( int i = 0; i < 39; i++ ){
		int r = GetRand(5);
		switch( r ){
			case 0: hp++; break;
			case 1: speed++; break;
			case 2: chargeMAX++; break;
			case 3: 
			case 4: 
			case 5: luck++; break;
			default: luck++;
		}
	}
}

void CCharactor::SetRandom()
{
	for( int i = 0; i < 39; i++ ){
		int r = GetRand(3);
		switch( r ){
			case 0: hp++; break;
			case 1: speed++; break;
			case 2: chargeMAX++; break;
			case 3: luck++; break;
			default: hp++;
		}
	}
}

// 初期化
void CCharactor::Initialize( TYPE t ){
	switch( t ){
		case TYPE::TOUGH:
			SetTough();
			break;
		case TYPE::QUICK:
			SetQuick();
			break;
		case TYPE::CHARGE:
			SetCharge();
			break;
		case TYPE::LUCKY:
			SetLuck();
			break;
		case TYPE::NORMAL:
		default:
			SetRandom();
	}
	// 画像読み込み
	int Graph = LoadGraph( "bullets.png" );
	GHandle = DerivationGraph( 0,80, 256, 256, Graph );	// 部分読み込み

	posX = 320;
	posY = 240;
}


// 更新
void CCharactor::Update()
{
	angle += 0.05;
	if( activeEffectA ){
		// 創造効果A
		alpha++;
		if( alpha > 255 ) {
			activeEffectA = false;
			endEffectA = true;
		}
	}
	if( angle > 360 ) angle = 0;
}

// 描画
void CCharactor::Draw()
{
	DrawFormatString( 0, 0, GetColor( 255, 255, 255 ), "name：%s", name );
	if( showStatus ){
		DrawFormatString( 0, 20, GetColor( 0, 255, 0 ), "HP：%d", hp );
		DrawFormatString( 0, 40, GetColor( 0, 0, 255 ), "speed：%d", speed );
		DrawFormatString( 0, 60, GetColor( 255, 0, 0 ), "chargeMAX：%d", chargeMAX);
		DrawFormatString( 0, 80, GetColor( 255, 255, 0 ), "luck：%d", luck );
	}
	SetDrawBlendMode( DX_BLENDMODE_ALPHA, alpha );
	DrawRotaGraph( posX, posY, 1.0, angle, GHandle, TRUE );
	SetDrawBlendMode( DX_BLENDMODE_NOBLEND, 0 );
}
