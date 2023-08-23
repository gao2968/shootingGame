#include "Enemy.h"
#include "GameMainScene.h"

Enemy::Enemy()
{
	location.x = 1100;
	location.y = 360;
	radius = 10;
}

Enemy::Enemy(int y, int type)
{
	enemyType = type;

	if (type == normal) {
		location.x = 1300;
		location.y = 100 + (y * 60);

		vec.movex = -1;
		vec.movey = 0;

		radius = 10;

		enemyRadius = 10;

		hp = 1;

		enemyBulletFlg = false;

		nWeapon = new NwaySpawner(1, 0.5f, 0.1f);

	}
	else if (type == boss) {
		location.x = 1300;
		location.y = 360;

		vec.movex = -1;
		vec.movey = 0;

		radius = 50;

		enemyRadius = 50;

		hp = 100;

		enemyBulletFlg = false;

		nWeapon = new NwaySpawner(3, 0.5f, 0.1f);
	}
	else if (type == mover) {
		location.x = 1300;
		location.y = 100 + (y * 60);

		vec.movex = -1;
		vec.movey = 1;

		radius = 10;

		enemyRadius = 10;

		hp = 1;

		enemyBulletFlg = false;

		nWeapon = new NwaySpawner(1, 0.5f, 0.1f);

		fps = 0;
		moverFlg = true;
	}
}

Enemy::~Enemy()
{
	delete weapon;
}

void Enemy::Update(GameMainScene* s)
{
	//’e‚Ì”­ŽË
	rand = GetRand(180);
	switch (enemyType)
	{
	case normal:
		if (rand % 180 == 0) {
			enemyBulletFlg = true;
			nWeapon->Shoot(s,normalBullet);
		}
		else {
			enemyBulletFlg = false;
		}
		break;
	case mover:
		if (rand % 120 == 0) {
			enemyBulletFlg = true;
			nWeapon->Shoot(s,normalBullet);
		}
		else {
			enemyBulletFlg = false;
		}
		break;
	case boss:
		if (rand % 60 == 0) {
			enemyBulletFlg = true;
			nWeapon->Shoot(s,normalBullet);
		}
		else {
			enemyBulletFlg = false;
		}
		break;
	}


	//ˆÚ“®

	switch (enemyType)
	{
	case normal:
		location.x += vec.movex;
		location.y += vec.movey;
		break;

	case mover:
		if (moverFlg) {
			vec.movey += 0.1f;
			
			if (vec.movey > 1) {
				if (++fps > 30) {
					fps = 0;
					moverFlg = false;
				}
			}
		}
		else{
			vec.movey += -0.1f;
			
			if (vec.movey < 0) {
				if (++fps > 30) {
					fps = 0;
					moverFlg = true;
				}
			}
		}
		location.x += vec.movex;
		location.y += vec.movey;
		break;

	case boss:
		if (location.x > 900) {
			location.x += vec.movex;
		}
		break;
	}
	
}

void Enemy::Draw() const
{
	DrawCircle(location.x, location.y, enemyRadius, 0xff00ff, TRUE);
	if (enemyType == boss) {
		DrawFormatString(location.x, location.y - 60, 0xffffff, "%d", hp);
	}
	//DrawFormatString(location.x, location.y - 60, 0xffffff, "%f", vec.movey);
}

int Enemy::Hit(int damage)
{
	hp -= damage;

	if (hp <= 0) {
		return TRUE;
	}

	return FALSE;
}
