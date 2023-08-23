#pragma once
#include "SphereCollider.h"
#include "MoveBullet.h"
#include "BulletsSpawner.h"

enum BULLET_TYPE
{
	normalBullet = 0,
	beamBullet
};

class Bullet : public SphereCollider
{
private:
	int damage;
	Vector vec;
	MoveBullet mb;
	int spawnFlg;	//ìGÇ™î≠éÀÇµÇΩíeÇ©ÉvÉåÉCÉÑÅ[Ç™î≠éÀÇµÇΩíeÇ©
	int bulletType;
public:
	Bullet();

	Bullet(BulletsSpawner* bs , Location l , int flg ,int type);

	~Bullet();

	void Update();
	void Draw() const;

	void ChangeAngle();

	int GetDamage() { return damage; }
	int getmb() { return mb.speed; }
	Location GetLocation() { return location; }
	int GetSpawnFlg() { return spawnFlg; }
	int GetBulletType() { return bulletType; }
	void SetMB(MoveBullet m)
	{
		mb = m;
	}
	void SetLocation(Location l)
	{
		location = l;
	}
};
