#pragma once
#include "AbstractScene.h"
class GameMainScene : public AbstractScene
{
private:

public:
	GameMainScene();
	~GameMainScene();

	void Update() override;				//�X�V����
	void Draw() const override;			//�`�揈��
	AbstractScene* Change() override;	//�J�ڐ�̎w��
};

