#include<iostream>
#include"ball.h"
#include<vector>
#include<conio.h>
#include<time.h>
#define _CRT_SECURE_NO_WARNINGS

using namespace std;
MOUSEMSG m;
ball b[16];
bool is_still()
{
	for (int i = 0;i < 16;++i) {
		if (b[i].getV()> 0.05||b[i].getV()< -0.05)return false;
	}
	return true;
}

void init()
{
	for (int i = 0;i < 16;++i) {
		char str[30];
		sprintf(str, "billiards_res/%d.jpg", i);
		loadimage(&b[i].img, str, 2 * r, 2 * r);
		b[i].setX(30 * i + r);
		b[i].setY(30 * i + r);
	}
}

void startgame()
{
	while (1) {
		cleardevice();
		if (is_still() && MouseHit()) {
			m = GetMouseMsg();
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				int dx = m.x - b[0].getX();
				int dy = m.y - b[0].getY();
				double dist = sqrt(dx*dx + dy * dy);
				b[0].setVX(100 * dx / dist);
				b[0].setVY(100 * dy / dist);
			}
			//FlushMouseMsgBuffer();
		}
		for (int i = 0;i < 16;++i)
		{
			b[i].move();
			b[i].CrashBorder();
			for (int j = 0;j < 16;++j)
			{
				if (j == i)continue;
				impact(b[i], b[j]);
			}
			b[i].display();
		}
		//Sleep(1);
	}
}
int main()
{
	//int G=0;
	void impact(ball & b1, ball &b2);
	initgraph(XMAX, YMAX);
	setbkcolor(RGB(223, 223, 223));
	//srand((unsigned(time(NULL))));
	//while (1) {
	//	cleardevice();
	//	if (MouseHit())
	//	{
	//		double angle = rand();
	//		double x = 50 * cos(angle);
	//		double y = 50 * sin(angle);
	//		m = GetMouseMsg();
	//		if (m.uMsg == WM_LBUTTONDOWN)
	//		{
	//			b.push_back(ball(1, x, y, 0, 0, m.x, m.y));
	//		}
	//		if (m.uMsg == WM_RBUTTONDOWN)
	//			G = !G;
	//	}
	//	for (int i=0;i < (int)b.size();++i)
	//	{
	//		b[i].setaY(10*G);
	//		b[i].move();
	//		b[i].CrashBorder();
	//		for (int j = 0;j < (int)b.size();++j)
	//		{
	//			if (j == i)continue;
	//			impact(b[i], b[j]);
	//		}
	//		b[i].display(0);
	//	}
	//	//Sleep(1);
	//}

	//TODO 初始化游戏
	init();
	//TODO 开始游戏
	startgame();
	return 0;
}