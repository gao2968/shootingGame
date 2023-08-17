#pragma once
#include "AbstractScene.h"
#include "Player.h"
#include "Enemy.h"
#include "Bullet.h"

class GameMainScene : public AbstractScene
{
public:
	Player player;
	int life;
	//Enemy* enemy;		//=new int[n]みたいな感じで動的にメモリを確保する
	
	Bullet* bullet[100]; /*= new Bullet()*/		//bulletも同じ
	int bNum = 0;  //球数管理
	int a;
public:
	GameMainScene();
	~GameMainScene();

	void Update() override;				//更新処理
	void Draw() const override;			//描画処理
	AbstractScene* Change() override;	//遷移先の指定

	int HitCheak();
	void SpawnBullet(BulletsSpawner* bs);
};

