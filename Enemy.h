#pragma once
#include "CharaBase.h"
class Enemy : public CharaBase
{
private:
	int hp;
	int point;
	//BulletsSpawner�̃|�C���^�^
public:
	Enemy();
	~Enemy();
	
	void Update(AbstractScene* s) override;
	void Draw() const override;
	int Hit(int damage) override;
};

