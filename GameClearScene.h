#pragma once
#include "AbstractScene.h"
class GameClearScene : public AbstractScene
{
private:

public:
	GameClearScene();
	~GameClearScene();

	void Update() override;				//�X�V����
	void Draw() const override;			//�`�揈��
	AbstractScene* Change() override;	//�J�ڐ�̎w��
};

