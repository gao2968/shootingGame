#pragma once
#include "AbstractScene.h"
#include "Ranking.h"
#include <string>

class InputRankingScene : public AbstractScene
{
private:
	char alphabet[3][26] = {
	   { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' },
	   { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' },
	   { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' }
	};

	std::string inputName;
	int selecter;
	
public:
	InputRankingScene();
	~InputRankingScene();

	void Update() override;				//XVˆ—
	void Draw() const override;			//•`‰æˆ—
	AbstractScene* Change() override;	//‘JˆÚæ‚Ìw’è
};

