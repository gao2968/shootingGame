#include "Bullet.h"
#include "DxLib.h"
#define _USE_MATH_DEFINES
#include <math.h>

Bullet::Bullet()
{
}

Bullet::Bullet(BulletsSpawner* bs, Location l, int flg, int type)
{
	if (type == normalBullet) {
		location = l;
		if (flg == TRUE)
		{
			location.x += 20;
		}
		else if (flg == FALSE)
		{
			location.x -= 20;
		}
		mb = bs->GetMove();
		radius = 5;
		spawnFlg = flg;
		bulletType = type;
		damage = 1;
	}
	else if (type == beamBullet) {
		location = l;
		if (flg == TRUE)
		{
			location.x += 20;
		}
		else if (flg == FALSE)
		{
			location.x -= 20;
		}
		mb = bs->GetMove();
		radius = 5;
		spawnFlg = flg;
		bulletType = type;
		damage = 10;
	}
}

Bullet::~Bullet()
{
}

void Bullet::Update()
{
	if (bulletType == normalBullet) {
		//’e‚ÌˆÚ“®“™‚ğ‹L“ü
		ChangeAngle();
		location.x += vec.movex;
		location.y += vec.movey;
	}
	else if (bulletType == beamBullet) {
		ChangeAngle();
		mb.speed += mb.acceleration;
		location.x += vec.movex;
		location.y += vec.movey;
	}
}

void Bullet::Draw() const
{
	if (bulletType == normalBullet) {
		if (spawnFlg == TRUE) {
			DrawCircle(location.x, location.y, 5, 0x00ff00, TRUE);
		}
		else {
			DrawCircle(location.x, location.y, 5, 0xf0ff00, TRUE);
		}
	}
	else if (bulletType == beamBullet) {
		DrawBox(location.x, location.y - 5, location.x + 100, location.y + 5, 0x00ff00, TRUE);
	}
}

void Bullet::ChangeAngle()
{
	//Šp“x‚©‚çˆÚ“®•ûŒü‚Ìİ’è
	float rad = mb.angle * (float)M_PI * 2;
	vec.movex = (int)(mb.speed * cosf(rad));
	vec.movey = (int)(mb.speed * sinf(rad));
}
