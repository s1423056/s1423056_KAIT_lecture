// charactor.h
// �L�����N�^�̃N���X

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
	TCHAR name[32];	// ���O
	int hp;						// �̗�
	int speed;				// �f����
	int chargeMAX;		// �^��MAX
	int luck;					// �^

	bool showStatus;		// �X�e�[�^�X��\�����邩�ǂ���
	bool activeEffectA;	// �n������A���J�n���ꂽ���ǂ���
	bool activeEffectB;	// �n������B���J�n���ꂽ���ǂ���
	bool endEffectA;		// �n������A���I���������ǂ���
	bool endEffectB;		// �n������B���I���������ǂ���

	int GHandle;	// �O���t�B�b�N�n���h��
	int alpha;			// �s�����x
	int posX, posY;	// �����w�\���ʒu
	double angle;	// ��]�p

	// ���ꂼ��̃^�C�v���Ńp�����[�^���U��
	void SetTough();
	void SetQuick();
	void SetCharge();
	void SetLuck();
	void SetRandom();

public:
	// �R���X�g���N�^
	CCharactor();

	// �L�����N�^������
	void Initialize( TYPE t );

	// �X�V
	void Update();

	// �`��
	void Draw();

	// ���O�ݒ�
	TCHAR* GetName(){ return name; }

	// �X�e�[�^�X�\���ؑ�
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

	// �X�e�[�^�X�擾
	int GetHP(){return hp; }
	int GetSpeed(){ return speed; }
	int GetChargeMAX(){ return chargeMAX; }
	int GetLuck(){ return luck;}

	// �X�e�[�^�X�ݒ�
	void SetHP( int val ){ hp = val; }
	void SetSpeed( int val ){ speed = val; }
	void SetChargeMAX( int val ){ chargeMAX = val; }
	void SetLuck( int val ){ luck = val; }

	// ��Ԑ��l�̍����X�e�[�^�X��Ԃ�
	STATUS GetMaxStatus(){
		STATUS st = NONE;
		if( hp > speed && hp > chargeMAX && hp > luck ) st = HP;
		if( speed > hp && speed > chargeMAX && speed > luck) st = SPEED;
		if( chargeMAX > hp && chargeMAX > speed && chargeMAX > luck ) st = CHARGEMAX;
		if( luck > hp && luck > speed && luck > chargeMAX ) st = LUCK;
			return st;
	}

	// �ʒu�擾
	int GetPosX(){ return posX; }
	int GetPosY(){ return posY; }

	// �p�x�擾
	float GetAngle(){ return angle; }

	// �X�e�[�^�X���Z
	void AddHP( int val ){ hp += val; }
	void AddSpeed( int val ){ speed += val; }
	void AddChargeMAX( int val ){ chargeMAX += val; }
	void AddLuck( int val ){ luck += val; }

	// �n������
	void EffectA(){ activeEffectA = true; }
	void EffectB(){ activeEffectB = true; }
};

#endif