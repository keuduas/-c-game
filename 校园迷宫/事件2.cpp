#include<string.h>
#include<graphics.h>
#include<time.h>
#include<conio.h>
void shijian2(int a[32][18], int* x1, int* y1, int* x2, int* y2, int* c) {
	void outputchar(TCHAR str[], int x, int y);
	void shuchu(int a[32][18], int x, int y, int x2, int y2);
	IMAGE P1; IMAGE P2; IMAGE P3; IMAGE P4; IMAGE P5; IMAGE P6;
	loadimage(&P1, _T("image/陶行染.png"), 450, 800);
	loadimage(&P2, _T("image/遮罩1.png"), 450, 800);
	loadimage(&P3, _T("image/文本框.png"), 680, 240);
	loadimage(&P4, _T("image/遮罩6.png"), 680, 240);
	loadimage(&P5, _T("image/偏差李一.png"), 450, 800);
	loadimage(&P6, _T("image/遮罩2.png"), 450, 800);
	putimage(0, 0, &P2, SRCAND);
	putimage(0, 0, &P1, SRCPAINT);
	putimage(220, 550, &P4, SRCAND);
	putimage(220, 550, &P3, SRCPAINT);
	TCHAR p[7][100]; int n = 1; char ch;
	_tcscpy_s(p[0], L"陶行染：好安静呀，这是我的学校吗？好奇怪的布局呀？");
	_tcscpy_s(p[1], L"陶行染：那边有个人，话说这种情况下，有人反而可怕吧。等一下，那不是李一姐吗？");
	_tcscpy_s(p[2], L"陶行染：李一姐？");
	_tcscpy_s(p[3], L"陶行染：李一姐，你的脸？");
	_tcscpy_s(p[4], L"李一？：你应该在考试哦，不专心的话会挂科的哦。");
	_tcscpy_s(p[5], L"陶行染：不是，什么鬼，该死，果然还是逃跑吧！");
	_tcscpy_s(p[6], L"提示：躲避李一的追逐。否则会被抓回去考试。李一会穿墙的哦。");
	outputchar(p[0], 260, 600);
	while (1) {
		flushmessage();
		if (_kbhit()) {
			ch = _getch();
			if (ch == ' ') {
				shuchu(a, *x1, *y1, *x2, *y2);
				*c = 1;
				a[*x1][*y1] = 0;
				break;
			}
		}
		if (MouseHit()) {
			MOUSEMSG msg = GetMouseMsg();
			if (msg.uMsg == WM_LBUTTONDOWN) {
				if (n > 6) {
					shuchu(a, *x1, *y1, *x2, *y2);
					*c = 1;
					a[*x1][*y1] = 0;
					break;
				}
				BeginBatchDraw();
				shuchu(a, *x1, *y1, *x2, *y2);
				putimage(0, 0, &P2, SRCAND);
				putimage(0, 0, &P1, SRCPAINT);
				if (n == 1 || n == 2) {
					putimage(670, 0, &P6, SRCAND);
				}
				if (n > 2) {
					putimage(670, 0, &P6, SRCAND);
					putimage(670, 0, &P5, SRCPAINT);
				}
				putimage(220, 550, &P4, SRCAND);
				putimage(220, 550, &P3, SRCPAINT);
				EndBatchDraw();
				outputchar(p[n], 260, 600);
				n = n + 1;
			}
		}
	}
}