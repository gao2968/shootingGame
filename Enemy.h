#pragma once
#include "CharaBase.h"
class Enemy : public CharaBase
{
private:
	int hp;
	int point;
	//BulletsSpawnerのポインタ型
public:
	Enemy();
	~Enemy();

	void Update(GameMainScene* gamemain) override;
	void Draw() const override;
	int Hit(int damage) override;
};

