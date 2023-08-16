#include "GameMainScene.h"
#include "DxLib.h"



GameMainScene::GameMainScene()
{
}

GameMainScene::~GameMainScene()
{
	delete bullet;
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
	player.CheckCollision((SphereCollider)*bullet[0]);	//キャストしてSphereColliderの型にする enemyも同じ感じ 弾の数だけループする
	
	return 0;
}

void GameMainScene::SpawnBullet(BulletsSpawner* b)
{
	/*bullet[0] = player.*/
	for (int i = 0; i < bNum; i++) {
		//ここで使った弾とかを管理したい
	}
	if (b != nullptr) {
		//bullet[bNum].SetMB(b->GetMove());
	}
	bullet[bNum++] = new Bullet(b);
	player.getb()->Shoot();//いい感じに
	
}
