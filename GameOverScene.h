#pragma once
#include "AbstractScene.h"
class GameOverScene : public AbstractScene
{
private:

public:
	GameOverScene();
	~GameOverScene();

	void Update() override;				//更新処理
	void Draw() const override;			//描画処理
	AbstractScene* Change() override;	//遷移先の指定
};

