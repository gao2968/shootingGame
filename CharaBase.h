#pragma once
class GameMainScene;
#include "SphereCollider.h"
#include "AbstractScene.h"

class CharaBase : public SphereCollider
{
protected:
	Vector vec;
	int speed;
	int image;
public:
	virtual void Update(GameMainScene* s);  //引数にゲームメインシーンのポインタを受け取る 敵、プレイヤー、弾の情報を受け取る
	virtual void Draw() const;
	virtual int Hit(int damage);
};

