#pragma once
class Fps
{
private:
	int nextTime;
	int fpsCnt;
	int a = 0;
public:
	void FpsCtrl();
	void DrawFps();
};

