#pragma once
#include "BulletsSpawner.h"
class NwaySpawner : public BulletsSpawner
{
private:
	int numBullets;
	float baseAngle;
	float angleDiff;
public:
	NwaySpawner(int n, float base, float diff);
	void Shoot(GameMainScene* s, int type) override;
};
