#pragma once
class GameMainScene;
#include "AbstractScene.h"
#include "MoveBullet.h"
class BulletsSpawner
{
protected:
	MoveBullet moveBulletSP;

public:
	BulletsSpawner();
	BulletsSpawner(int f);
	~BulletsSpawner();
	virtual void Shoot(GameMainScene* s);
	MoveBullet GetMove() { return moveBulletSP; }

};

