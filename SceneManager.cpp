#include "SceneManager.h"
#include "DxLib.h"

SceneManager::SceneManager()
{
	now_scene = nullptr;
	next_scene = nullptr;
}

SceneManager::SceneManager(AbstractScene* scene)
{
	now_scene = scene;
	next_scene = now_scene;
}

SceneManager::~SceneManager()
{
	delete now_scene;
}

void SceneManager::Update()
{
	if (now_scene != nullptr)
	{
		now_scene->Update();
	}
}

void SceneManager::Draw() const
{
	ClearDrawScreen();

	if (now_scene != nullptr)
	{
		now_scene->Draw();
	}

	ScreenFlip();
}

AbstractScene* SceneManager::Change()
{
	//�J�ڐ���󂯎��
	next_scene = now_scene->Change();

	//�J�ڐ�̃V�[���ƌ��݂̃V�[��������Ă�����ύX
	if (next_scene != now_scene)
	{
		delete now_scene;
		now_scene = next_scene;
	}

	//�J�ڐ��ԋp
	return next_scene;
}
