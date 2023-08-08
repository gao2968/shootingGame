#include "DxLib.h"
#include "SceneManager.h"
#include "GameMainScene.h"

int WINAPI WinMain(_In_ HINSTANCE ih, _In_opt_ HINSTANCE ioh, _In_ LPSTR il, _In_ int ii)
{
	// ウィンドウモードで起動
	if (ChangeWindowMode(TRUE) != DX_CHANGESCREEN_OK)
	{
		return -1;
	}

	// DXライブラリの初期化
	if (DxLib_Init() == -1)
	{
		return -1;
	}

	//描画先の指定
	SetDrawScreen(DX_SCREEN_BACK);

	SceneManager sceneMng(dynamic_cast<AbstractScene*>(new GameMainScene()));

	//メインループ
	while (ProcessMessage() != -1)
	{
		sceneMng.Update();		//シーンの更新処理
		sceneMng.Draw();		//シーンの描画処理
		//シーンの変更処理
		if (sceneMng.Change() == nullptr)
		{
			break;
		}
	}

	// DXライブラリの終了処理
	DxLib_End();

	return 0;
}