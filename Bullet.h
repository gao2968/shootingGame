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
	int spawnFlg;	//“G‚ª”­Ë‚µ‚½’e‚©ƒvƒŒƒCƒ„[‚ª”­Ë‚µ‚½’e‚©
public:
	Bullet();

	Bullet(BulletsSpawner* bs , Location l , int flg);

	~Bullet();

	void Update();
	void Draw() const;

	void ChangeAngle();

	int GetDamage() { return damage; }
	int getmb() { return mb.speed; }
	Location GetLocation() { return location; }
	int GetSpawnFlg() { return spawnFlg; }
	void SetMB(MoveBullet m)
	{
		mb = m;
	}
	void SetLocation(Location l)
	{
		location = l;
	}
};
