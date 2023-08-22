#pragma once
#include "DxLib.h"

struct Location
{
	int x;
	int y;
};

struct Vector
{
	float movex;
	float movey;
};

class SphereCollider
{
protected:
	Location location;
	int radius;
public:
	int CheckCollision(SphereCollider sphereCollider);

};

