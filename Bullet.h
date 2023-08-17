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

	Bullet(BulletsSpawner* bs , Location l);

	~Bullet();

	void Update();
	void Draw() const;

	void ChangeAngle();

	int GetDamage() { return damage; }
	int getmb() { return mb.speed; }
	Location GetLocation() { return location; }
	void SetMB(MoveBullet m)
	{
		mb = m;
	}
	void SetLocation(Location l)
	{
		location = l;
	}
};
