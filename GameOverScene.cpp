#include "GameOverScene.h"
#include "DxLib.h"

GameOverScene::GameOverScene()
{
}

GameOverScene::~GameOverScene()
{
}

void GameOverScene::Update()
{
}

void GameOverScene::Draw() const
{
	DrawFormatString(0, 0, 0xffffff, "GameOver");
}

AbstractScene* GameOverScene::Change()
{
	return this;
}
