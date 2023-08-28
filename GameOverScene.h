#pragma once
#include "AbstractScene.h"
class GameOverScene : public AbstractScene
{
private:

public:
	GameOverScene();
	~GameOverScene();

	void Update() override;				//XVˆ—
	void Draw() const override;			//•`‰æˆ—
	AbstractScene* Change() override;	//‘JˆÚæ‚Ìw’è
};

