#include "Ranking.h"
#include <fstream>
#include <iostream>
#include <sstream>

Ranking::RANKING Ranking::rankingData[];

void Ranking::ReadRanking()
{
	//ランキングテキストの読込
	std::ifstream ifs("text/Ranking.txt");

	std::string line;
	//ランキングテキストの一行を取得
	for (int i = 0; std::getline(ifs, line); i++) {
		std::istringstream stream(line);
		std::string str;
		//no name scoreに分けて格納
		for (int j = 0; std::getline(stream, str, ','); j++) {
			if (j == 0) {
				rankingData[i].no = std::stoi(str);
			}
			else if (j == 1) {
				rankingData[i].name = str;
			}
			else {
				rankingData[i].score = std::stoi(str);
			}
		}
	}
}

void Ranking::WriteRanking(std::string n, int s)
{
	RANKING tmp;		//入れ替えの時に使う
	std::ofstream ofs("text/Ranking.txt");		//ランキングテキストの読込

	//ランキングデータの最下位に引数を代入
	rankingData[4].name = n;
	rankingData[4].score = s;
	//並べ替え
	for (int i = 0; i < 4; i++) {
		for (int j = i + 1; j < 5; j++) {
			if (rankingData[i].score < rankingData[j].score) {
				tmp = rankingData[i];
				rankingData[i] = rankingData[j];
				rankingData[j] = tmp;
			}
		}
	}

	//順位の再振り分け
	rankingData[0].no = 1;
	for (int i = 1; i < 5; i++) {
		//同じ点数だったら同じ順位
		if (rankingData[i].score == rankingData[i - 1].score) {
			rankingData[i].no = rankingData[i - 1].no;
		}
		//同じ順位じゃなければ一つ多い順位
		else {
			rankingData[i].no = i + 1;
		}
	}

	//ランキングテキストに書き込み
	for (int i = 0; i < 5; i++) {
		ofs << rankingData[i].no << "," << rankingData[i].name << "," << rankingData[i].score << std::endl;
	}
}
