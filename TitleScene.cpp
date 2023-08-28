#include "TitleScene.h"
#include "DxLib.h"

TitleScene::TitleScene()
{
}

TitleScene::~TitleScene()
{
}

void TitleScene::Update()
{
}

void TitleScene::Draw() const
{
	DrawFormatString(0, 0, 0xffffff, "Title");
}

AbstractScene* TitleScene::Change()
{
	return this;
}
