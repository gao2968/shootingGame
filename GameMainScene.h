#pragma once
#include "AbstractScene.h"
#include "Player.h"
#include "Enemy.h"
#include "Bullet.h"

#define SCROLL_SPEED 5
#define ENEMY_MAX 100
#define BULLETS_MAX 100

class GameMainScene : public AbstractScene
{
public:
	Player player;
	int life;
	//enemy関連
	Enemy* enemy[ENEMY_MAX];		//=new int[n]みたいな感じで動的にメモリを確保する
	int a;
	bool enemyBulletsFlg;
	int randEnemy;
	int rowEnemy;
	int bossNum;

	//bullet関連
	Bullet* bullet[BULLETS_MAX]; /*= new Bullet()*/		//bulletも同じ
	int bNum = 0;  //球数管理


	int img_Background;
	int backgroundX, backgroundY;

	int time;
public:
	GameMainScene();
	~GameMainScene();

	void Update() override;				//更新処理
	void Draw() const override;			//描画処理
	AbstractScene* Change() override;	//遷移先の指定

	int HitCheak();
	void SpawnBullet();
	void SpawnEnemy();

	Enemy* GetEnemy(int i) { return enemy[i]; }
};

