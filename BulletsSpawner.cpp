#include "BulletsSpawner.h"
#include "GameMainScene.h"

BulletsSpawner::BulletsSpawner()
{
	moveBulletSP.speed = 7;
	moveBulletSP.angle = 1.0f;
	moveBulletSP.acceleration = 2;
	moveBulletSP.angleVelocity = 1.0f;
}

BulletsSpawner::BulletsSpawner(int f)
{
	moveBulletSP.speed = 7;
	moveBulletSP.angle = 1.0f;
	moveBulletSP.acceleration = 2;
	moveBulletSP.angleVelocity = 1.0f;
}

BulletsSpawner::~BulletsSpawner()
{
}

void BulletsSpawner::Shoot(GameMainScene* s ,int type)
{
	
	s->SpawnBullet(type);

}
