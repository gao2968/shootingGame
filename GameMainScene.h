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
	//enemy�֘A
	Enemy* enemy[ENEMY_MAX];		//=new int[n]�݂����Ȋ����œ��I�Ƀ��������m�ۂ���
	int a;
	bool enemyBulletsFlg;
	int randEnemy;
	int rowEnemy;
	int bossNum;

	//bullet�֘A
	Bullet* bullet[BULLETS_MAX]; /*= new Bullet()*/		//bullet������
	int bNum = 0;  //�����Ǘ�


	int img_Background;
	int backgroundX, backgroundY;

	int time;
public:
	GameMainScene();
	~GameMainScene();

	void Update() override;				//�X�V����
	void Draw() const override;			//�`�揈��
	AbstractScene* Change() override;	//�J�ڐ�̎w��

	int HitCheak();
	void SpawnBullet();
	void SpawnEnemy();

	Enemy* GetEnemy(int i) { return enemy[i]; }
};

