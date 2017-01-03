// system.cpp
// �V�X�e���̍���

#include "system.h"

// �R���X�g���N�^
CSystem::CSystem(){
	// �L�[�z�񏉊���
	GetHitKeyStateAll( key );
	GetHitKeyStateAll( pre_key );
}

// ������
void CSystem::Initialize()
{
	DrawString( 0, 0, "���O����́F",GetColor( 255,255,255 ) );
	KeyInputString( 100, 0, 31, charactor.GetName(), FALSE );
	ClearDrawScreen();
	DrawString( 0, 0, "�^�C�v����́F",GetColor( 255,255,255 ) );
	DrawString( 0, 30, "0:�̗͌^�@1�F�X�s�[�h�^�@2�F�`���[�W�^�F3 ���b�N�^�@4�F���ό^", GetColor( 255,255,255 ) );
	TYPE t = (TYPE)KeyInputNumber( 120, 0, 5, 0, FALSE );
	charactor.Initialize( t );
	CBullet::LoadGraphic();
	attack = defense = charge = enemyHP = 0;
	sHandle0 = LoadSoundMem( "Randomize.wav" );
	sHandle1 = LoadSoundMem( "shoot.wav" );
}

// �X�V
void CSystem::Update()
{
	GetHitKeyStateAll( key );

	// �X�e�[�^�X�\���ؑ�
	if( key[KEY_INPUT_S] == 1 && pre_key[KEY_INPUT_S] == 0 )
		charactor.ToggleShowStatus();

	// �n������A
	if( key[KEY_INPUT_A] == 1 && pre_key[KEY_INPUT_A] == 0 ){
		charactor.EffectA();
		BulletColor c;
			switch( charactor.GetMaxStatus() ){
				case HP: c = GREEN; break;
				case SPEED: c = BLUE; break;
				case CHARGEMAX: c = RED; break;
				case LUCK: c = YELLOW; break;
				default: WHITE;
			}
		for( int i = 0; i < 100; i++ ){
			
			bullets.push_back( new CBullet(320, 280, GetRand(1000)/1000.0f * 3 + 1.0f, 
				GetRand(180), GetRand(1000)/1000.0f / 2, -90.0, c ) );
		}
		PlaySoundMem( sHandle0, DX_PLAYTYPE_BACK );
	}

	// �퓬�p�����[�^�U�蕪��
	if( key[KEY_INPUT_Z] == 1 && pre_key[KEY_INPUT_Z] == 0 ){
		int c = charge;
		attack = 0; defense = 0; charge = 0;
		for(int i = 0; i < 7+c; i++ ){
			int r;
			if( charactor.GetHP() < 5 ) r = 1;	// �s���`�̎��͂��߂Ȃ�
			else r = 2;
			switch( GetRand(r) ){
				case 0: attack++; break;
				case 1: defense++; break;
				case 2: charge++; break;
				default: attack++;
			}
		}
		if( charge > charactor.GetChargeMAX() ) charge = charactor.GetChargeMAX();
		ClearDrawScreen();
		DrawFormatString( 0, 0, GetColor( 255,255,255 ), "�U���F%d�@�h��F%d�@�^���F%d", attack, defense, charge );
		charactor.SetEndEffectB( false );
		charactor.SetActiveEffectB( false );
		WaitKey();
	}

	// �c��̗͂Ƒ���̗̑͂����
	if( key[KEY_INPUT_X] == 1 && pre_key[KEY_INPUT_X] == 0 ){
		ClearDrawScreen();
		DrawString( 0, 0, "�c��̗́F", GetColor( 255,255,255 ) );
		int life = KeyInputNumber( 80, 0, 100, 0, FALSE );
		charactor.SetHP( life );
	
		if( charactor.GetHP() < 0 ){
			ClearDrawScreen();
			SetFontSize( 32 );
			DrawString( 0, 0, "�������I", GetColor( 255, 0, 0 ) );
			WaitKey();
			end = true;
		}

		ClearDrawScreen();
		DrawString( 0, 0, "����̗̑�", GetColor( 255, 255, 255 ) );
		DrawString( 0, 30, "enemyHP�F",GetColor( 255, 255, 255 ) );
		int val = KeyInputNumber( 82, 30, 40, 0, FALSE );
		enemyHP = val;
	}

	// �n������B�N��
	if( key[KEY_INPUT_B] == 1 && pre_key[KEY_INPUT_B] == 0 && charactor.GetEndEffectB() == false ){
		charactor.EffectB();
	}

	// �n������B
	if( charactor.GetActiveEffectB() && !charactor.GetEndEffectB() ){
		static int num, time;
		int delay;
		
		if( enemyHP < 20 ){
			if( charactor.GetHP() < 5 ) delay = 60;
			else delay = 20;
			if( time % delay == 0 ){
				for( int i = 0; i < attack;i ++){
					bullets.push_back( new CBullet( charactor.GetPosX(), charactor.GetPosY(), 3.0f, 
						charactor.GetAngle() + i * 360/attack + time, 0.0f, 0.0f, (BulletColor)(num % COLOR_NUM) ) );
				}
				PlaySoundMem( sHandle1, DX_PLAYTYPE_BACK );
				num++;
			}
		}
		else{
			if( time % 100 == 0 ){
				for( int i = 0; i < attack; i++ ){
					bullets.push_back( new CBullet( charactor.GetPosX(), charactor.GetPosY(), 3.0f,
						60.0f + i * 60.0f / attack, 0.0f, 0.0f, YELLOW ) );
				}
				for( int i = 0; i < attack; i++ ){
					bullets.push_back( new CBullet( charactor.GetPosX(), charactor.GetPosY(), 3.0f,
						60.0f + i * 60.0f / attack, 0.02f, 60.0f + i * 60.0f / attack, ORANGE) );
				}
				for( int i = 0; i < attack; i++ ){
					bullets.push_back( new CBullet( charactor.GetPosX(), charactor.GetPosY(), 3.0f,
						60.0f + i * 60.0f / attack, 0.04f, 60.0f + i * 60.0f / attack, RED) );
				}

				for( int i = 0; i < attack; i++ ){
					bullets.push_back( new CBullet( charactor.GetPosX(), charactor.GetPosY(), 3.0f,
						180.0f + i * 60.0f / attack, 0.0f, 180.0f + i * 60.0f / attack, YELLOW ) );
				}
				for( int i = 0; i < attack; i++ ){
					bullets.push_back( new CBullet( charactor.GetPosX(), charactor.GetPosY(), 3.0f,
						180.0f + i * 60.0f / attack, 0.02f, 180.0f + i * 60.0f / attack, ORANGE) );
				}
				for( int i = 0; i < attack; i++ ){
					bullets.push_back( new CBullet( charactor.GetPosX(), charactor.GetPosY(), 3.0f,
						180.0f + i * 60.0f / attack, 0.04f, 180.0f + i * 60.0f / attack, RED) );
				}

				for( int i = 0; i < attack; i++ ){
					bullets.push_back( new CBullet( charactor.GetPosX(), charactor.GetPosY(), 3.0f,
						300.0f + i * 60.0f / attack, 0.0f, 300.0f + i * 60.0f / attack, YELLOW ) );
				}
				for( int i = 0; i < attack; i++ ){
					bullets.push_back( new CBullet( charactor.GetPosX(), charactor.GetPosY(), 3.0f,
						300.0f + i * 60.0f / attack, 0.02f, 300.0f + i * 60.0f / attack, ORANGE) );
				}
				for( int i = 0; i < attack; i++ ){
					bullets.push_back( new CBullet( charactor.GetPosX(), charactor.GetPosY(), 3.0f,
						300.0f + i * 60.0f / attack, 0.04f, 300.0f + i * 60.0f / attack, RED) );
				}
				PlaySoundMem( sHandle1, DX_PLAYTYPE_BACK );
			}
		}

		time++;
		if( time > 600 ) {
			time = 0;
			charactor.SetEndEffectB( true );
		}
	}

	// �ŏI����X�e�[�^�X����
	if( charactor.GetEndEffectA() ){
		DrawString( 0, 128, "�̗͂����", GetColor( 255, 255, 255 ) );
		DrawString( 0, 152, "HP�F", GetColor( 0, 255, 0 ) );
		int val = KeyInputNumber( 52, 152, 40, 0, FALSE );
		charactor.SetHP( val );
		ClearDrawScreen();

		DrawString( 0, 128, "���x�����", GetColor( 255, 255, 255 ) );
		DrawString( 0, 152, "speed�F", GetColor( 0, 0, 255 ) );
		val = KeyInputNumber( 70, 152, 40, 0, FALSE );
		charactor.SetSpeed( val );
		ClearDrawScreen();

		DrawString( 0, 128, "����MAX", GetColor( 255, 255, 255 ) );
		DrawString( 0, 152, "chargeMAX�F", GetColor( 255, 0, 0 ) );
		val = KeyInputNumber( 102, 152, 40, 0, FALSE );
		charactor.SetChargeMAX( val );
		ClearDrawScreen();
		
		DrawString( 0, 128, "�^", GetColor( 255, 255, 255 ) );
		DrawString( 0, 152, "luck�F", GetColor( 255, 255, 0) );
		val = KeyInputNumber( 52, 152, 40, 0, FALSE );
		charactor.SetLuck( val );
		ClearDrawScreen();

		DrawString( 0, 128, "����̗̑�", GetColor( 255, 255, 255 ) );
		DrawString( 0, 152, "enemyHP�F",GetColor( 255, 255, 255 ) );
		val = KeyInputNumber( 82, 152, 40, 0, FALSE );
		enemyHP = val;

		charactor.SetEndEffectA( false );

	}

	charactor.Update();

	for( ite = bullets.begin(); ite != bullets.end(); ){
		(*ite) -> Update();
		if( (*ite) -> GetActive() == false ){
			delete *ite;
			ite = bullets.erase(ite);
			continue;
		} 
		ite++;
	}

	for( int i = 0; i < 256; i++ ) pre_key[i] = key[i];
}

// �`��
void CSystem::Draw()
{
	charactor.Draw();
	for( ite = bullets.begin(); ite != bullets.end(); ite++ )
		(*ite) -> Draw();
}
