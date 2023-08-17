#include "BulletsSpawner.h"
#include "GameMainScene.h"

void BulletsSpawner::Shoot(AbstractScene* s)
{
	moveBulletSP.speed = 6;
	moveBulletSP.angle = 1.0f;
	moveBulletSP.acceleration = 2;
	moveBulletSP.angleVelocity = 1.0f;

}
