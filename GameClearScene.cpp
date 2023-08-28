#include "GameClearScene.h"
#include "DxLib.h"

GameClearScene::GameClearScene()
{
}

GameClearScene::~GameClearScene()
{
}

void GameClearScene::Update()
{
}

void GameClearScene::Draw() const
{
	DrawFormatString(0, 0, 0xffffff, "GameClear");
}

AbstractScene* GameClearScene::Change()
{
	return this;
}
