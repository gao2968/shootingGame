#pragma once
#include "CharaBase.h"
#include "NwaySpawner.h"

class Player : public CharaBase
{
private:
	int score;
	//BulletsSpawnerのポインタ型
	BulletsSpawner* bs = new BulletsSpawner(TRUE);
	NwaySpawner* nWeapon ;
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

