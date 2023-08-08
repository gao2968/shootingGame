#pragma once
#include "AbstractScene.h"
class SceneManager : public AbstractScene
{
private:
	AbstractScene* now_scene;		//現在のシーン
	AbstractScene* next_scene;		//次のシーン

public:
	SceneManager();					//コンストラクタ
	SceneManager(AbstractScene* scene);	//引数付きコンストラクタ(次のシーン)
	~SceneManager();				//デストラクタ

	void Update() override;			//更新処理
	void Draw() const override;		//描画処理
	AbstractScene* Change() override;//遷移先の指定
};

