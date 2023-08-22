#pragma once
#include "CharaBase.h"
#include "NwaySpawner.h"

enum ENEMY_TYPE
{
	normal = 0,
	mover,
	boss
};

class Enemy : public CharaBase
{
private:
	int hp;
	int point;
	//BulletsSpawner‚Ìƒ|ƒCƒ“ƒ^Œ^
	BulletsSpawner* weapon = new BulletsSpawner();
	NwaySpawner* nWeapon;

	int enemyRadius;

	int enemyType;

	int rand;
	bool enemyBulletFlg;

	int fps;
	bool moverFlg;
public:
	Enemy();
	Enemy(int y, int type);
	~Enemy();
	
	void Update(GameMainScene* s) override;
	void Draw() const override;
	int Hit(int damage) override;

	Location GetEnemyLoacation() { return location; }
	NwaySpawner* GetNwaySpawner() { return nWeapon; }
	bool GetEnemyBulletFlg() { return enemyBulletFlg; }
};

