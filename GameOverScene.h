#pragma once
#include "AbstractScene.h"
class GameOverScene : public AbstractScene
{
private:

public:
	GameOverScene();
	~GameOverScene();

	void Update() override;				//�X�V����
	void Draw() const override;			//�`�揈��
	AbstractScene* Change() override;	//�J�ڐ�̎w��
};

