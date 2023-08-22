#include "Enemy.h"
#include "GameMainScene.h"

Enemy::Enemy()
{
	location.x = 1100;
	location.y = 360;
	radius = 10;
}

Enemy::Enemy(int y)
{
	location.x = 1100;
	location.y = 100 + (y * 60);
	radius = 10;
	enemyBulletFlg = false;
}

Enemy::~Enemy()
{
	delete bs;
}

void Enemy::Update(GameMainScene* s)
{
	rand = GetRand(180);

	if (rand % 120 == 0) {
		enemyBulletFlg = true;
		nbs->Shoot(s);
	}
	else {
		enemyBulletFlg = false;
	}



}

void Enemy::Draw() const
{
	DrawCircle(location.x, location.y, 10, 0xff00ff, TRUE);
}

int Enemy::Hit(int damage)
{
	return 0;
}
