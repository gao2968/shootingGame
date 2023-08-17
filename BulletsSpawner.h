#pragma once
#include "AbstractScene.h"
#include "MoveBullet.h"
class BulletsSpawner
{
private:
	MoveBullet moveBulletSP;

public:
	virtual void Shoot(AbstractScene* s);
	MoveBullet GetMove() { return moveBulletSP; }

};

