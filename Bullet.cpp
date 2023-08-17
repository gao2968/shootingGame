#include "Bullet.h"
#include "DxLib.h"
#define _USE_MATH_DEFINES
#include <math.h>

Bullet::Bullet()
{
}

Bullet::Bullet(BulletsSpawner* bs , Location l)
{
	location = l;
	mb = bs->GetMove();
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
	DrawCircle(location.x, location.y, 5, 0x00ff00, TRUE);
}

void Bullet::ChangeAngle()
{
	//Šp“x‚©‚çˆÚ“®•ûŒü‚Ìİ’è
	float rad = mb.angle * (float)M_PI * 2;
	vec.movex = (int)(mb.speed * cosf(rad));
	vec.movey = (int)(mb.speed * sinf(rad));
}
