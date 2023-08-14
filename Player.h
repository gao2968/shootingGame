#pragma once
#include "CharaBase.h"
class Player : public CharaBase
{
private:
	int score;
	//BulletsSpawner‚Ìƒ|ƒCƒ“ƒ^Œ^
public:
	Player();
	~Player();

	void Update(GameMainScene* gamemain) override;
	void Draw() const override;
	int Hit(int damage) override;
};

