#include "player.h"
#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <time.h>
using namespace std;

player::player(){
	cout << "���O����͂��Ă��������F";
	cin >> name;
	point = 0;
	fist = 0;
	npcnum = 0;
}

player::player(int num){
	npcnum = num;
	strcpy(name,"NPC"+(char)num);
	srand((unsigned)time(NULL));
}

int player::take(){
	if( npcnum == 0){
		cout << "����񂯂�ۂ�(�O�[�F1  �`���L�F2  �p�[�F3) �F";
		cin >> fist;
	}
	else{
		
		fist = rand()%3+1;
	}
	char f[16];
	switch(fist){
		case 1:strcpy(f,"�O�[");break;
		case 2:strcpy(f,"�`���L");break;
		case 3:strcpy(f,"�p�[");break;
	}
	cout << name <<"��"<< f << "���o���܂����B\n";
	return fist;
}

int player::getfist(){
	return fist;
}

void player::setpoint(int score){
	point += score;
}