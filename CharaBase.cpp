#include "CharaBase.h"

void CharaBase::Update(AbstractScene* s)
{
	//gamemainのhitchaekを呼び出しtrueだったらhitを呼び出し処理を記入
}

void CharaBase::Draw() const
{
	//画像描画をCharaBaseで行う（仮）
	DrawGraph(location.x, location.y, image, TRUE);
}

int CharaBase::Hit(int damage)
{
	//当たった後の処理
	//playerとenemyの共通処理内容を記述、例　当たった弾を消す（要追記）
	return 0;
}
