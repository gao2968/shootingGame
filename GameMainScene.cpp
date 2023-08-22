#include "GameMainScene.h"
#include "DxLib.h"



GameMainScene::GameMainScene()
{
	for (int i = 0; i < BULLETS_MAX; i++)
	{
		bullet[i] = nullptr;
	}

	for (int i = 0; i < 10; i++)
	{
		enemy[i] = nullptr;
	}

	a = 0;
	enemyBulletsFlg = false;
	img_Background = LoadGraph("images/background.jpg");
	backgroundX, backgroundY = 0;

	time = 0;
}

GameMainScene::~GameMainScene()
{
	for (int i = 0; i < BULLETS_MAX; i++){
		if (bullet[i] != nullptr){
			delete bullet;
		}
	}
	for (int i = 0; i < ENEMY_MAX; i++)
	{
		if (enemy[i] != nullptr) {
			delete enemy;
		}
	}
	
}

void GameMainScene::Update()
{
	player.Update(this);

	if (++time == 300) {
		for (int i = 0; i < ENEMY_MAX; i++) {
			if (enemy[i] == nullptr) {
				enemy[i] = new Enemy(0, boss);
				bossNum = i;
				break;
			}
		}
	}
	SpawnEnemy();

	for (int i = 0; i < ENEMY_MAX; i++){
		if (enemy[i] != nullptr) {
			enemy[i]->Update(this);
			//敵の削除
			if (enemy[i]->GetEnemyLoacation().x < -30) {
				enemy[i] = nullptr;
			}
		}
	}

	HitCheak();


	//弾の削除
	for (int i = 0; i < BULLETS_MAX; i++) {
		if (bullet[i] != nullptr) {
			bullet[i]->Update();
			if (bullet[i]->GetLocation().x > 1280 || bullet[i]->GetLocation().x < 0 ||
				bullet[i]->GetLocation().y > 720 || bullet[i]->GetLocation().y < 0) {
				//delete bullet[i];
				bullet[i] = nullptr;
			}
		}
	}

	backgroundX -= SCROLL_SPEED;
	if (backgroundX <= -2048) {
		backgroundX = 0;
	}

}

void GameMainScene::Draw() const
{
	DrawGraph(backgroundX, backgroundY, img_Background, FALSE);
	DrawGraph(backgroundX + 2048, backgroundY, img_Background, FALSE);
	DrawFormatString(0, 0, 0xffffff, "GameMain");
	DrawCircle(1280, 720, 5, 0xffffff, 1);
	player.Draw();

	for (int i = 0; i < ENEMY_MAX; i++)
	{
		if (enemy[i] != nullptr) {
			enemy[i]->Draw();
		}
	}

	for (int i = 0; i < BULLETS_MAX; i++) {
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
	
	for (int i = 0; i < BULLETS_MAX; i++) {
		if (bullet[i] != nullptr && bullet[i]->GetSpawnFlg() == TRUE) {
			for (int j = 0; j < ENEMY_MAX; j++){
				if (enemy[j] != nullptr) {
					if (bullet[i]->CheckCollision(static_cast<SphereCollider>(*enemy[j])) == TRUE){
						//ここにenemy[j].Hitを入れる
						if (enemy[j]->Hit(1) == TRUE) {
							enemy[j] = nullptr;
						}
						bullet[i] = nullptr;
						break;
					}
				}
			}
		}
	}

	for (int i = 0; i < BULLETS_MAX; i++) {
		if (bullet[i] != nullptr) {
			if (bullet[i]->CheckCollision(static_cast<SphereCollider>(player)) == TRUE) {
				//プレイヤーが弾に当たった時の処理
				player.SetPlayerLocation(30, 320);
				bullet[i] = nullptr;
				break;
			}
		}
	}

	return 0;
}

void GameMainScene::SpawnBullet()
{
	/*bullet[0] = player.*/
	//for (int i = 0; i < bNum; i++) {
	//	//ここで使った弾とかを管理したい
	//}
	//if (b != nullptr) {
	//	//bullet[bNum].SetMB(b->GetMove());
	//}
	//bullet[bNum++] = new Bullet(b);
	
	for (int i = 0; i < BULLETS_MAX; i++){
		if (bullet[i] == nullptr) {
			if (player.GetPlayerBulletFlg()) {
				bullet[i] = new Bullet(static_cast<BulletsSpawner*>(player.GetNwaySpawner()), player.GetLocation(), TRUE);
				break;
			}
		}
	}

	for (int i = 0; i < BULLETS_MAX; i++){
		if (bullet[i] == nullptr) {
			for (int j = 0; j < ENEMY_MAX; j++) {
				if (enemy[j] != nullptr) {
					if (enemy[j]->GetEnemyBulletFlg()) {
						bullet[i] = new Bullet(static_cast<BulletsSpawner*>(enemy[j]->GetNwaySpawner()), enemy[j]->GetEnemyLoacation(), FALSE);
						enemyBulletsFlg = true;
						break;
					}
				}
			}
			if (enemyBulletsFlg) {
				enemyBulletsFlg = false;
				break;
			}
		}
	}
	
}

void GameMainScene::SpawnEnemy()
{
	randEnemy = GetRand(240);

	if (randEnemy % 240 == 0) {
		for (int i = 0; i < ENEMY_MAX; i++){
			if (enemy[i] == nullptr) {
				enemy[i] = new Enemy(GetRand(9), GetRand(1));
				break;
			}
		}
	}
}
