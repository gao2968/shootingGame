#pragma once
#include "SphereCollider.h"
#include "GameMainScene.h"

class CharaBase : public SphereCollider
{
protected:
	Vector vec;
	int speed;
	int image;
public:
	virtual void Update(GameMainScene* gamemain);  //�����ɃQ�[�����C���V�[���̃|�C���^���󂯎�� �G�A�v���C���[�A�e�̏����󂯎��
	virtual void Draw() const;
	virtual int Hit(int damage);
};

