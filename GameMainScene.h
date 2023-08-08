#pragma once
#include "AbstractScene.h"
class GameMainScene : public AbstractScene
{
private:

public:
	GameMainScene();
	~GameMainScene();

	void Update() override;				//XVˆ—
	void Draw() const override;			//•`‰æˆ—
	AbstractScene* Change() override;	//‘JˆÚæ‚Ìw’è
};

