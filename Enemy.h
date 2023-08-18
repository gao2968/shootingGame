#pragma once
#include "CharaBase.h"
#include "NwaySpawner.h"
class Enemy : public CharaBase
{
private:
	int hp;
	int point;
	//BulletsSpawner‚Ìƒ|ƒCƒ“ƒ^Œ^
	BulletsSpawner* bs = new BulletsSpawner();
	NwaySpawner* nbs = new NwaySpawner(1, 0.5f, 0.1f);

	int rand;
	bool enemyBulletFlg;
public:
	Enemy();
	Enemy(int y);
	~Enemy();
	
	void Update(GameMainScene* s) override;
	void Draw() const override;
	int Hit(int damage) override;

	Location GetEnemyLoacation() { return location; }
	NwaySpawner* GetNwaySpawner() { return nbs; }
	bool GetEnemyBulletFlg() { return enemyBulletFlg; }
};

