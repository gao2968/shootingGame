#include "Bullet.h"
#include "DxLib.h"
#define _USE_MATH_DEFINES
#include <math.h>

Bullet::Bullet()
{
}

Bullet::Bullet(BulletsSpawner* bs, Location l, int flg)
{
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
}

Bullet::~Bullet()
{
}

void Bullet::Update()
{
	//’e‚ÌˆÚ“®“™‚ğ‹L“ü
	ChangeAngle();
	location.x += vec.movex;
	location.y += vec.movey;
}

void Bullet::Draw() const
{
	if (spawnFlg == TRUE) {
		DrawCircle(location.x, location.y, 5, 0x00ff00, TRUE);
	}
	else {
		DrawCircle(location.x, location.y, 5, 0xf0ff00, TRUE);
	}
}

void Bullet::ChangeAngle()
{
	//Šp“x‚©‚çˆÚ“®•ûŒü‚Ìİ’è
	float rad = mb.angle * (float)M_PI * 2;
	vec.movex = (int)(mb.speed * cosf(rad));
	vec.movey = (int)(mb.speed * sinf(rad));
}
