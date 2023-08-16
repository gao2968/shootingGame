#pragma once
#include "CharaBase.h"
#include "BulletsSpawner.h"

class Player : public CharaBase
{
private:
	int score;
	//BulletsSpawnerのポインタ型
	BulletsSpawner* bs = new BulletsSpawner();
	
	
public:
	Player();
	~Player();

	void Update(AbstractScene* s) override;
	void Draw() const override;
	int Hit(int damage) override;

	BulletsSpawner* getb() { return bs; }
};

