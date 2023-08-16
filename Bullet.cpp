#include "Bullet.h"
#include "DxLib.h"

Bullet::Bullet()
{
}

Bullet::Bullet(BulletsSpawner* bs)
{
}

Bullet::~Bullet()
{
}

void Bullet::Update()
{
	//’e‚ÌˆÚ“®“™‚ð‹L“ü
}

void Bullet::Draw() const
{
	DrawCircle(location.x, location.y, 0xff0000, TRUE);
}
