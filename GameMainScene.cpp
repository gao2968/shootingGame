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
	//player.CheckCollision((SphereCollider)*bullet[0]);	//�L���X�g����SphereCollider�̌^�ɂ��� enemy���������� �e�̐��������[�v����
	
	return 0;
}

void GameMainScene::SpawnBullet(BulletsSpawner* bs)
{
	/*bullet[0] = player.*/
	//for (int i = 0; i < bNum; i++) {
	//	//�����Ŏg�����e�Ƃ����Ǘ�������
	//}
	//if (b != nullptr) {
	//	//bullet[bNum].SetMB(b->GetMove());
	//}
	//bullet[bNum++] = new Bullet(b);
	
	//if (player.GetBulletSpawnFlg()) {
		for (int i = 0; i < 100; i++){
			if (bullet[i] == nullptr) {

				//player.getb()->Shoot(this);//����������
				bullet[i] = new Bullet(bs, player.GetLocation());
				
				/*player.getb()->GetMove();
				bullet[i]->SetMB(player.getb()->GetMove());
				bullet[i]->SetLocation(player.GetLocation());*/
				break;
			}
		}
	//}
}
