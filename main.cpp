#include "DxLib.h"
#include "SceneManager.h"
#include "GameMainScene.h"

int WINAPI WinMain(_In_ HINSTANCE ih, _In_opt_ HINSTANCE ioh, _In_ LPSTR il, _In_ int ii)
{
	// �E�B���h�E���[�h�ŋN��
	if (ChangeWindowMode(TRUE) != DX_CHANGESCREEN_OK)
	{
		return -1;
	}

	// DX���C�u�����̏�����
	if (DxLib_Init() == -1)
	{
		return -1;
	}

	//�`���̎w��
	SetDrawScreen(DX_SCREEN_BACK);

	SceneManager sceneMng(dynamic_cast<AbstractScene*>(new GameMainScene()));

	//���C�����[�v
	while (ProcessMessage() != -1)
	{
		sceneMng.Update();		//�V�[���̍X�V����
		sceneMng.Draw();		//�V�[���̕`�揈��
		//�V�[���̕ύX����
		if (sceneMng.Change() == nullptr)
		{
			break;
		}
	}

	// DX���C�u�����̏I������
	DxLib_End();

	return 0;
}