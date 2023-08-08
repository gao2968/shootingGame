#pragma once

class AbstractScene
{
public:
	//�`��ȊO�̍X�V������
	virtual void Update() = 0;

	//�`��Ɋւ��邱�Ƃ�����
	virtual void Draw() const = 0;

	//�V�[���؂�ւ�
	virtual AbstractScene* Change() = 0;
};
