#pragma once
#include "AbstractScene.h"

class BulletsSpawner
{
private:
	int speed = 0;
	float angle = 0;
	int acceleration = 0;
	float angulVelocity = 0;
public:
	virtual void Shoot(AbstractScene* s);
};

