#pragma once
#include "DxLib.h"

struct Location
{
	int x;
	int y;
};

struct Vector
{
	int movex;
	int movey;
};

class SphereCollider
{
protected:
	Location location;
	int radius;
public:
	int CheckCollision(SphereCollider sphereCollider);

};

