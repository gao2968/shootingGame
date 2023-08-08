#pragma once
#include "AbstractScene.h"
class SceneManager : public AbstractScene
{
private:
	AbstractScene* now_scene;		//���݂̃V�[��
	AbstractScene* next_scene;		//���̃V�[��

public:
	SceneManager();					//�R���X�g���N�^
	SceneManager(AbstractScene* scene);	//�����t���R���X�g���N�^(���̃V�[��)
	~SceneManager();				//�f�X�g���N�^

	void Update() override;			//�X�V����
	void Draw() const override;		//�`�揈��
	AbstractScene* Change() override;//�J�ڐ�̎w��
};

