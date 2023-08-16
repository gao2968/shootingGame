#pragma once
#include "BulletsSpawner.h"
class NwaySpawner : public BulletsSpawner
{
private:
	int numBullets;
	float baseAngle;
	float angleDiff;
public:
	void Shoot(AbstractScene* s) override;
};
