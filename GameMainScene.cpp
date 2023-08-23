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

	/*if (f == 0) {
		bullet[99] = new Bullet(static_cast<BulletsSpawner*>(player.GetNwaySpawner()), player.GetLocation(), TRUE, beamBullet);
		f = 1;
	}*/

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
			//“G‚Ìíœ
			if (enemy[i]->GetEnemyLoacation().x < -30) {
				enemy[i] = nullptr;
			}
		}
	}

	HitCheak();


	//’e‚Ìíœ
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
	//player.CheckCollision((SphereCollider)*bullet[0]);	//ƒLƒƒƒXƒg‚µ‚ÄSphereCollider‚ÌŒ^‚É‚·‚é enemy‚à“¯‚¶Š´‚¶ ’e‚Ì”‚¾‚¯ƒ‹[ƒv‚·‚é
	
	for (int i = 0; i < BULLETS_MAX; i++) {
		if (bullet[i] != nullptr && bullet[i]->GetSpawnFlg() == TRUE) {//“G‚Ì’e‚ª“G‚É“–‚½‚ç‚È‚¢‚æ‚¤‚É‚·‚é
			for (int j = 0; j < ENEMY_MAX; j++){
				if (enemy[j] != nullptr) {

					if (bullet[i]->GetBulletType() == normalBullet) {
						if (bullet[i]->CheckCollision(static_cast<SphereCollider>(*enemy[j])) == TRUE) {
							//‚±‚±‚Éenemy[j].Hit‚ğ“ü‚ê‚é
							if (enemy[j]->Hit(bullet[i]->GetDamage()) == TRUE) {
								enemy[j] = nullptr;
							}
							bullet[i] = nullptr;
							break;
						}
					}

					if (bullet[i]->GetBulletType() == beamBullet) {
						if (bullet[i]->CheckCollisionBox(static_cast<SphereCollider>(*enemy[j])) == TRUE) {
							//‚±‚±‚Éenemy[j].Hit‚ğ“ü‚ê‚é
							if (enemy[j]->Hit(bullet[i]->GetDamage()) == TRUE) {
								enemy[j] = nullptr;
							}
							bullet[i] = nullptr;
							break;
						}
					}

				}
			}
		}
	}

	for (int i = 0; i < BULLETS_MAX; i++) {
		if (bullet[i] != nullptr && bullet[i]->GetSpawnFlg() == FALSE) {
			if (bullet[i]->CheckCollision(static_cast<SphereCollider>(player)) == TRUE) {
				//ƒvƒŒƒCƒ„[‚ª’e‚É“–‚½‚Á‚½‚Ìˆ—
				player.SetPlayerLocation(30, 320);
				bullet[i] = nullptr;
				break;
			}
		}
	}

	return 0;
}

void GameMainScene::SpawnBullet(int type)
{
	/*bullet[0] = player.*/
	//for (int i = 0; i < bNum; i++) {
	//	//‚±‚±‚Åg‚Á‚½’e‚Æ‚©‚ğŠÇ—‚µ‚½‚¢
	//}
	//if (b != nullptr) {
	//	//bullet[bNum].SetMB(b->GetMove());
	//}
	//bullet[bNum++] = new Bullet(b);
	
	for (int i = 0; i < BULLETS_MAX; i++){
		if (bullet[i] == nullptr) {
			if (player.GetPlayerBulletFlg()) {
				switch (type)
				{
				case normalBullet:
					bullet[i] = new Bullet(static_cast<BulletsSpawner*>(player.GetNwaySpawner()), player.GetLocation(), TRUE, normalBullet);
					break;
				case beamBullet:
					bullet[i] = new Bullet(static_cast<BulletsSpawner*>(player.GetNwaySpawner()), player.GetLocation(), TRUE, beamBullet);
					break;
				}
				
				break;
			}
		}
	}

	for (int i = 0; i < BULLETS_MAX; i++){
		if (bullet[i] == nullptr) {
			for (int j = 0; j < ENEMY_MAX; j++) {
				if (enemy[j] != nullptr) {
					if (enemy[j]->GetEnemyBulletFlg()) {
						bullet[i] = new Bullet(static_cast<BulletsSpawner*>(enemy[j]->GetNwaySpawner()), enemy[j]->GetEnemyLoacation(), FALSE ,normalBullet);
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
