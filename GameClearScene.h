#pragma once
#include "AbstractScene.h"
class GameClearScene : public AbstractScene
{
private:

public:
	GameClearScene();
	~GameClearScene();

	void Update() override;				//XVˆ—
	void Draw() const override;			//•`‰æˆ—
	AbstractScene* Change() override;	//‘JˆÚæ‚Ìw’è
};

