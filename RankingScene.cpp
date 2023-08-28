#include "RankingScene.h"
#include "DxLib.h"

RankingScene::RankingScene()
{
}

RankingScene::~RankingScene()
{
}

void RankingScene::Update()
{
}

void RankingScene::Draw() const
{
	DrawFormatString(0, 0, 0xffffff, "Ranking");
}

AbstractScene* RankingScene::Change()
{
	return this;
}
