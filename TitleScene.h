#pragma once
#include "AbstractScene.h"
class TitleScene : public AbstractScene
{
private:

public:
	TitleScene();
	~TitleScene();

	void Update() override;				//�X�V����
	void Draw() const override;			//�`�揈��
	AbstractScene* Change() override;	//�J�ڐ�̎w��
};

