#include "GameMainScene.h"
#include "DxLib.h"



GameMainScene::GameMainScene()
{
	for (int i = 0; i < 100; i++)
	{
		bullet[i] = nullptr;
	}
}

GameMainScene::~GameMainScene()
{
	for (int i = 0; i < 100; i++){
		if (bullet[i] != nullptr){
			delete bullet;
		}
	}
	
}

void GameMainScene::Update()
{
	player.Update(this);
	//SpawnBullet();
	for (int i = 0; i < 100; i++) {
		if (bullet[i] != nullptr) {
			bullet[i]->Update();
			if (bullet[i]->GetLocation().x > 1280 || bullet[i]->GetLocation().x < 0 ||
				bullet[i]->GetLocation().y > 720 || bullet[i]->GetLocation().y < 0) {
				//delete bullet[i];
				bullet[i] = nullptr;
			}
		}
	}
}

void GameMainScene::Draw() const
{
	DrawFormatString(0, 0, 0xffffff, "GameMain");
	DrawCircle(1280, 720, 5, 0xffffff, 1);
	player.Draw();
	for (int i = 0; i < 100; i++) {
		if (bullet[i] != nullptr) {
			bullet[i]->Draw();
		}
	}

}

AbstractScene* GameMainScene::Change()
{
	return this;
}

int GameMainScene::HitCheak()
{
	//player.CheckCollision((SphereCollider)*bullet[0]);	//キャストしてSphereColliderの型にする enemyも同じ感じ 弾の数だけループする
	
	return 0;
}

void GameMainScene::SpawnBullet(BulletsSpawner* bs)
{
	/*bullet[0] = player.*/
	//for (int i = 0; i < bNum; i++) {
	//	//ここで使った弾とかを管理したい
	//}
	//if (b != nullptr) {
	//	//bullet[bNum].SetMB(b->GetMove());
	//}
	//bullet[bNum++] = new Bullet(b);
	
	//if (player.GetBulletSpawnFlg()) {
		for (int i = 0; i < 100; i++){
			if (bullet[i] == nullptr) {

				//player.getb()->Shoot(this);//いい感じに
				bullet[i] = new Bullet(bs, player.GetLocation());
				
				/*player.getb()->GetMove();
				bullet[i]->SetMB(player.getb()->GetMove());
				bullet[i]->SetLocation(player.GetLocation());*/
				break;
			}
		}
	//}
}
