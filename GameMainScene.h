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
	//Enemy* enemy;		//=new int[n]�݂����Ȋ����œ��I�Ƀ��������m�ۂ���
	
	Bullet* bullet[100]; /*= new Bullet()*/		//bullet������
	int bNum = 0;  //�����Ǘ�
	int a;
public:
	GameMainScene();
	~GameMainScene();

	void Update() override;				//�X�V����
	void Draw() const override;			//�`�揈��
	AbstractScene* Change() override;	//�J�ڐ�̎w��

	int HitCheak();
	void SpawnBullet(BulletsSpawner* bs);
};

