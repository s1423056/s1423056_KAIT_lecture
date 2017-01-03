// system.h
// �V�X�e���̍���

#ifndef _SYSTEM_H
#define _SYSTEM_H

#include <DxLib.h>
#include <list>
#include "charactor.h"
#include "bullet.h"
using namespace std;

class CSystem
{
private:
	char key[256];
	char pre_key[256];
	CCharactor charactor;
	list<CBullet*> bullets;
	list<CBullet*>::iterator ite;
	int sHandle0,sHandle1;		// �T�E���h�n���h��
	bool end = false;

	int attack;
	int defense;
	int charge;
	int k;	// �^�[����

	int enemyHP;	// ����̗̑�

public:
	CSystem();
	void Initialize();
	void Update();
	void Draw();
	bool GetEnd(){ return end;}
};


#endif