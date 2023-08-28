#include "InputRankingScene.h"
#include "DxLib.h"
#include "InputControl.h"

InputRankingScene::InputRankingScene()
{
	selecter = 0;
	inputName = "";
}

InputRankingScene::~InputRankingScene()
{
}

void InputRankingScene::Update()
{
	if (InputControl::OnButton(XINPUT_BUTTON_DPAD_UP)) {
		if (selecter >= 0 && selecter <= 25) {
			selecter += 52;
		}
		else {
			selecter -= 26;
		}
	}

	if (InputControl::OnButton(XINPUT_BUTTON_DPAD_DOWN)) {
		if (selecter >= 52 && selecter <= 61) {
			selecter -= 52;
		}
		else {
			selecter += 26;
		}
	}
	
	if (InputControl::OnButton(XINPUT_BUTTON_DPAD_LEFT)) {
		if (selecter % 26 == 0) {
			selecter += 25;
		}
		else {
			selecter -= 1;
		}
	}

	if (InputControl::OnButton(XINPUT_BUTTON_DPAD_RIGHT)) {
		if (selecter == 25 || selecter == 51) {
			selecter -= 25;
		}
		else {
			selecter += 1;
		}
	}

	if (selecter > 61) {
		selecter = 61;
	}

	if (InputControl::OnButton(XINPUT_BUTTON_B)) {
		int x, y;
		if (selecter >= 0 && selecter <= 25) {
			y = 0;
		}
		else if (selecter >= 26 && selecter <= 51) {
			y = 1;
		}
		else {
			y = 2;
		}
		x = selecter % 26;
		inputName += alphabet[y][x];
	}
}

void InputRankingScene::Draw() const
{
	DrawFormatString(0, 0, 0xffffff, "InputRankig");
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 26; j++){
			DrawFormatString((j + 1) * 30, (i + 1) * 30, 0xffffff, "%c", alphabet[i][j]);
		}
	}

	DrawFormatString(400, 0, 0xffffff, "selecter::%d", selecter);
	DrawFormatString(550, 0, 0xffffff, "inputname::%s", inputName.c_str());
	//DrawBox((selecter % 26)*30, (selecter % 3)*30, selecter / 26 + 30, selecter / 3 + 30, 0xffffff, TRUE);
	//DrawCircle((selecter % 26) * 30, (selecter % 3) * 30, 5, 0xffffff, TRUE);
	if (selecter >= 0 && selecter <= 25) {
		DrawCircle((selecter % 26 + 1) * 30, 30, 5, 0xffffff, TRUE);
	}
	else if (selecter >= 26 && selecter <= 51) {
		DrawCircle((selecter % 26 + 1) * 30, 60, 5, 0xffffff, TRUE);
	}
	else {
		DrawCircle((selecter % 26 + 1) * 30, 90, 5, 0xffffff, TRUE);
	}
}

AbstractScene* InputRankingScene::Change()
{
	return this;
}
