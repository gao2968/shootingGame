#pragma once
#include "AbstractScene.h"
#include "Ranking.h"

class RankingScene : public AbstractScene
{
private:

public:
	RankingScene();
	~RankingScene();

	void Update() override;				//XVˆ—
	void Draw() const override;			//•`‰æˆ—
	AbstractScene* Change() override;	//‘JˆÚæ‚Ìw’è
};

