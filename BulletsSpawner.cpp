#include "BulletsSpawner.h"
#include "GameMainScene.h"

void BulletsSpawner::Shoot(AbstractScene* s)
{
	speed = 5;
	angle = 1.0f;
	acceleration = 2;
	angulVelocity = 1.0f;
	
	GameMainScene::SpawnBullet();
}
