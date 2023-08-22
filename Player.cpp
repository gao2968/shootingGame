#include "Player.h"
#include "InputControl.h"
#include "GameMainScene.h"

Player::Player()
{
	location.x = 30;
	location.y = 320;
	radius = 5;
	playerBulletFlg = false;
	fps = 0;
}

Player::~Player()
{
	delete bs;
}

void Player::Update(GameMainScene* s)
{
	if (InputControl::OnPressed(XINPUT_BUTTON_DPAD_UP)) {
		vec.movey = -5;
	}
	else if (InputControl::OnPressed(XINPUT_BUTTON_DPAD_DOWN)) {
		vec.movey = 5;
	}
	else {
		vec.movey = 0;
	}

	if (InputControl::OnPressed(XINPUT_BUTTON_DPAD_LEFT)) {
		vec.movex = -5;
	}
	else if (InputControl::OnPressed(XINPUT_BUTTON_DPAD_RIGHT)) {
		vec.movex = 5;
	}
	else {
		vec.movex = 0;
	}
	
	location.y += vec.movey;
	location.x += vec.movex;


	if (InputControl::OnButton(XINPUT_BUTTON_B) || (InputControl::OnPressed(XINPUT_BUTTON_B) && ++fps % 20 == 0)) {
		playerBulletFlg = true;
		nbs->Shoot(s);
	}
	else {
		playerBulletFlg = false;
	}
	
	
}

void Player::Draw() const
{
	DrawCircle(location.x, location.y, 5, 0xff0000, TRUE);
}

int Player::Hit(int damage)
{
	return 0;
}
