#pragma once
#include "SphereCollider.h"
class Bullet : public SphereCollider
{
private:
	int damage;
	Vector vec;
	int speed;
	float angle;
	int acceleration;
	float angulVelocity;
public:
	Bullet();
	~Bullet();

	void Update();
	void Draw() const;
	int GetDamage() { return damage; }
};
