#pragma once
#include "AbstractScene.h"
class TitleScene : public AbstractScene
{
private:

public:
	TitleScene();
	~TitleScene();

	void Update() override;				//XVˆ—
	void Draw() const override;			//•`‰æˆ—
	AbstractScene* Change() override;	//‘JˆÚæ‚Ìw’è
};

