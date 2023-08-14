#include "Fps.h"
#include "DxLib.h"

void Fps::FpsCtrl()
{
	nextTime = GetNowCount();
	nextTime += 15;
	if (nextTime > GetNowCount()) {
		WaitTimer(nextTime - GetNowCount());
	}
}

void Fps::DrawFps()
{
	fpsCnt++;
	if (fpsCnt % 60 == 0) {
		a++;
	}
	DrawFormatString(50, 50, 0xffffff, "%d", a);
}
