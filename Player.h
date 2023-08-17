#pragma once
#include "CharaBase.h"
#include "BulletsSpawner.h"

class Player : public CharaBase
{
private:
	int score;
	//BulletsSpawner�̃|�C���^�^
	BulletsSpawner* bs = new BulletsSpawner();
	
	bool bulletSpawnFlg;
public:
	Player();
	~Player();

	void Update(GameMainScene* s) override;
	void Draw() const override;
	int Hit(int damage) override;

	BulletsSpawner* getb() { return bs; }
	bool GetBulletSpawnFlg() { return bulletSpawnFlg; }
	Location GetLocation() { return location; }
};

