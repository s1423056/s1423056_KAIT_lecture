// barrage.h
// 弾幕のクラス

#ifndef _BARRAGE_H
#define _BARRAGE_H

#include <list>
#include "bullet.h"
using namespace std;

class CBarrage
{
private:
	list<CBullet> bullets;	// 　弾のリスト
};

#endif