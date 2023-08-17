#pragma once
class GameMainScene;
#include "AbstractScene.h"
#include "MoveBullet.h"
class BulletsSpawner
{
private:
	MoveBullet moveBulletSP;

public:
	virtual void Shoot(GameMainScene* s);
	MoveBullet GetMove() { return moveBulletSP; }

};

