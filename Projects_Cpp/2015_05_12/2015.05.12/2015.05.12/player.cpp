#include "player.h"
#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <time.h>
using namespace std;

player::player(){
	cout << "名前を入力してください：";
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
		cout << "じゃんけんぽん(グー：1  チョキ：2  パー：3) ：";
		cin >> fist;
	}
	else{
		
		fist = rand()%3+1;
	}
	char f[16];
	switch(fist){
		case 1:strcpy(f,"グー");break;
		case 2:strcpy(f,"チョキ");break;
		case 3:strcpy(f,"パー");break;
	}
	cout << name <<"は"<< f << "を出しました。\n";
	return fist;
}

int player::getfist(){
	return fist;
}

void player::setpoint(int score){
	point += score;
}