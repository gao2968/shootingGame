#include "GameMainScene.h"
#include "DxLib.h"

GameMainScene::GameMainScene()
{
}

GameMainScene::~GameMainScene()
{
}

void GameMainScene::Update()
{
	player.Update(this);

}

void GameMainScene::Draw() const
{
	DrawFormatString(0, 0, 0xffffff, "GameMain");
	DrawCircle(1280, 720, 5, 0xffffff, 1);
	player.Draw();
}

AbstractScene* GameMainScene::Change()
{
	return this;
}

int GameMainScene::HitCheak()
{
	player.CheckCollision((SphereCollider)bullet[0]);	//キャストしてSphereColliderの型にする enemyも同じ感じ 弾の数だけループする
	return 0;
}

void GameMainScene::SpawnBullet()
{
	/*bullet[0] = player.*/
}
