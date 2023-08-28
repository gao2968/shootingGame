#pragma once
#include <string>
class Ranking
{
public:
	//�����L���O�\����
	struct RANKING
	{
		int no;					//����
		std::string name;		//���O
		int score;				//�X�R�A
	};

private:
	static RANKING rankingData[5];		//�����L���O�f�[�^�i�[�p

public:
	//�����L���O�̓Ǎ�
	static void ReadRanking();
	//�����L���O�̏������ݗp
	//�����Fn ���O�@s �X�R�A
	static void WriteRanking(std::string n, int s);

	//�����L���O�f�[�^�̎擾
	//�����Fnum�@�擾�������f�[�^�̔ԍ�
	//�߂�l�Fnum�Ŏw�肳�ꂽ�ԍ���rankingData��ԋp
	static RANKING GetRankingData(int num)
	{
		return rankingData[num];
	}
};


