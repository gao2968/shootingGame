#pragma once
#include "AbstractScene.h"
#include "Ranking.h"

class RankingScene : public AbstractScene
{
private:

public:
	RankingScene();
	~RankingScene();

	void Update() override;				//�X�V����
	void Draw() const override;			//�`�揈��
	AbstractScene* Change() override;	//�J�ڐ�̎w��
};

