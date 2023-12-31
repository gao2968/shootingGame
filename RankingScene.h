#pragma once
#include "AbstractScene.h"
#include "Ranking.h"

class RankingScene : public AbstractScene
{
private:

public:
	RankingScene();
	~RankingScene();

	void Update() override;				//更新処理
	void Draw() const override;			//描画処理
	AbstractScene* Change() override;	//遷移先の指定
};

