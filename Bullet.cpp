#include "Bullet.h"
#include "DxLib.h"

Bullet::Bullet()
{
}

Bullet::~Bullet()
{
}

void Bullet::Update()
{
	//弾の移動等を記入
}

void Bullet::Draw() const
{
	DrawCircle(location.x, location.y, 0xff0000, TRUE);
}
