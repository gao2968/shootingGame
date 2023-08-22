#pragma once
#include "CharaBase.h"
#include "NwaySpawner.h"

class Player : public CharaBase
{
private:
	int score;
	//BulletsSpawner‚Ìƒ|ƒCƒ“ƒ^Œ^
	BulletsSpawner* bs = new BulletsSpawner(TRUE);
	NwaySpawner* nWeapon = new NwaySpawner(3, 1.0f, 0.1f);
	bool playerBulletFlg;
	int fps;
public:
	Player();
	~Player();

	void Update(GameMainScene* s) override;
	void Draw() const override;
	int Hit(int damage) override;

	BulletsSpawner* GetBulletsSpawner() { return bs; }
	NwaySpawner* GetNwaySpawner() { return nWeapon; }
	Location GetLocation() { return location; }
	bool GetPlayerBulletFlg() { return playerBulletFlg; }

	void SetPlayerLocation(int x, int y)
	{
		location.x = x;
		location.y = y;
	}
};

