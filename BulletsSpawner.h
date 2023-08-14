#pragma once
#include "GameMainScene.h"

class BulletsSpawner
{
private:
	int speed;
	float angle;
	int acceleration;
	float angulVelocity;
public:
	virtual void Shoot(GameMainScene* gamemain);
};

