#include "Ranking.h"
#include <fstream>
#include <iostream>
#include <sstream>

Ranking::RANKING Ranking::rankingData[];

void Ranking::ReadRanking()
{
	//�����L���O�e�L�X�g�̓Ǎ�
	std::ifstream ifs("text/Ranking.txt");

	std::string line;
	//�����L���O�e�L�X�g�̈�s���擾
	for (int i = 0; std::getline(ifs, line); i++) {
		std::istringstream stream(line);
		std::string str;
		//no name score�ɕ����Ċi�[
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
	RANKING tmp;		//����ւ��̎��Ɏg��
	std::ofstream ofs("text/Ranking.txt");		//�����L���O�e�L�X�g�̓Ǎ�

	//�����L���O�f�[�^�̍ŉ��ʂɈ�������
	rankingData[4].name = n;
	rankingData[4].score = s;
	//���בւ�
	for (int i = 0; i < 4; i++) {
		for (int j = i + 1; j < 5; j++) {
			if (rankingData[i].score < rankingData[j].score) {
				tmp = rankingData[i];
				rankingData[i] = rankingData[j];
				rankingData[j] = tmp;
			}
		}
	}

	//���ʂ̍ĐU�蕪��
	rankingData[0].no = 1;
	for (int i = 1; i < 5; i++) {
		//�����_���������瓯������
		if (rankingData[i].score == rankingData[i - 1].score) {
			rankingData[i].no = rankingData[i - 1].no;
		}
		//�������ʂ���Ȃ���Έ��������
		else {
			rankingData[i].no = i + 1;
		}
	}

	//�����L���O�e�L�X�g�ɏ�������
	for (int i = 0; i < 5; i++) {
		ofs << rankingData[i].no << "," << rankingData[i].name << "," << rankingData[i].score << std::endl;
	}
}
