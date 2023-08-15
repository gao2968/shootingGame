#include "DxLib.h"
#include "Fps.h"
#include "SceneManager.h"
#include "GameMainScene.h"
#include "InputControl.h"

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

	//ウィンドウサイズ設定
	SetGraphMode(1280, 720, 32);
	SetWindowSize(1280, 720);

	//描画先の指定
	SetDrawScreen(DX_SCREEN_BACK);

	SceneManager sceneMng(dynamic_cast<AbstractScene*>(new GameMainScene()));
	Fps fps;
	
	//メインループ
	while (ProcessMessage() != -1)
	{
		fps.FpsCtrl();
		InputControl::UpdateKey();
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