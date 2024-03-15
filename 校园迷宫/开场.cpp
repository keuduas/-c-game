#include<graphics.h>
#include<iostream>
#include<conio.h>
#pragma comment(lib,"winmm.lib")

void kaichang()
{

	
	IMAGE P1, P2, P5, P6, P7;
	loadimage(&P7, _T("image/开场.jpg"), 1120, 800);
	putimage(0, 0, &P7);

	setbkmode(TRANSPARENT);
	srand((unsigned int)time(NULL));
	mciSendString(_T("open music/开场音乐.mp3 alias bkmusic"), NULL, 0, NULL);
	mciSendString(_T("play bkmusic repeat"), NULL, 0, NULL);
	int x = 10,flag=1;
	settextcolor(BLACK);
	settextstyle(30, 20, _T("方正字迹-阿庆逸行体 简"), 0, 0, 1000, NULL, NULL, NULL);
	outtextxy(750, 400, _T(">>点击任意键继续"));
	MOUSEMSG msg;
	while (flag)
	{
		settextcolor(RGB(rand() % 255, rand() % 255, rand() % 255));
		settextstyle(100, 100, _T("智勇手书体"), 0, 0, 1000, NULL, NULL, NULL);
		outtextxy(350, 100, _T("迷宫"));
		if (_kbhit())
		{
			mciSendString(_T("close bkmusic"), NULL, 0, NULL);
			flag = 0;
		}
	}
	_getch();
	

}