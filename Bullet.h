#pragma once
#include "SphereCollider.h"
#include "MoveBullet.h"
#include "BulletsSpawner.h"
class Bullet : public SphereCollider
{
private:
	int damage;
	Vector vec;
	MoveBullet mb;
public:
	Bullet();

	Bullet(BulletsSpawner* bs);

	~Bullet();

	void Update();
	void Draw() const;
	int GetDamage() { return damage; }
	void SetMB(MoveBullet m)
	{
		mb = m;
	}
};
