#include "NwaySpawner.h"
#include "GameMainScene.h"

NwaySpawner::NwaySpawner(int n, float base, float diff)
{
	numBullets = n;
	baseAngle = base;
	angleDiff = diff;
}

void NwaySpawner::Shoot(GameMainScene* s)
{
	/*for (int i = 0; i < 10; i++)
	{
		s->GetEnemy(i);
	}*/
	
	for (int i = 0; i < numBullets; i++)
	{
		switch (i)
		{
		case 0:
			moveBulletSP.angle = baseAngle;
			break;
		case 1:
			moveBulletSP.angle = baseAngle + angleDiff;
			break;
		case 2:
			moveBulletSP.angle = baseAngle - angleDiff;
			break;
		default:
			break;
		}

		BulletsSpawner::Shoot(s);
	}
	
}
