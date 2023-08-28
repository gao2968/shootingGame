#pragma once
#include <string>
class Ranking
{
public:
	//ランキング構造体
	struct RANKING
	{
		int no;					//順位
		std::string name;		//名前
		int score;				//スコア
	};

private:
	static RANKING rankingData[5];		//ランキングデータ格納用

public:
	//ランキングの読込
	static void ReadRanking();
	//ランキングの書き込み用
	//引数：n 名前　s スコア
	static void WriteRanking(std::string n, int s);

	//ランキングデータの取得
	//引数：num　取得したいデータの番号
	//戻り値：numで指定された番号のrankingDataを返却
	static RANKING GetRankingData(int num)
	{
		return rankingData[num];
	}
};


