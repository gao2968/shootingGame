#pragma once

struct Loacation
{
	int x;
	int y;
};

class SphereCollider
{
private:
	Loacation location;
	int radius;
public:
	int CheckCollision(SphereCollider sphereCollider);
};

