#pragma once

struct Loacation
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
	Loacation location;
	int radius;
public:
	int CheckCollision(SphereCollider sphereCollider);
};

