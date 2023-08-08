#pragma once

class AbstractScene
{
public:
	//描画以外の更新を実装
	virtual void Update() = 0;

	//描画に関することを実装
	virtual void Draw() const = 0;

	//シーン切り替え
	virtual AbstractScene* Change() = 0;
};
