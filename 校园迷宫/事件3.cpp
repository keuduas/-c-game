#include<string.h>
#include<graphics.h>
#include<time.h>
#include<conio.h>
void shijian3(int a[32][18], int* x1, int* y1, int* x2, int* y2, int b[17]) {
	void outputchar(TCHAR str[], int x, int y);
	void shuchu(int a[32][18], int x, int y, int x2, int y2);
	IMAGE P1; IMAGE P2; IMAGE P3; IMAGE P4;
	loadimage(&P1, _T("image/陶行染.png"), 450, 800);
	loadimage(&P2, _T("image/遮罩1.png"), 450, 800);
	loadimage(&P3, _T("image/文本框.png"), 680, 240);
	loadimage(&P4, _T("image/遮罩6.png"), 680, 240);
	putimage(0, 0, &P2, SRCAND);
	putimage(0, 0, &P1, SRCPAINT);
	putimage(220, 550, &P4, SRCAND);
	putimage(220, 550, &P3, SRCPAINT);
	TCHAR p[4][100]; int n = 1;
	_tcscpy_s(p[0], L"陶行染：几支笔，为啥会在这里？");
	_tcscpy_s(p[1], L"陶行染：不算太脏，貌似是有人用过的，笔芯只有一半了。");
	_tcscpy_s(p[2], L"陶行染：带上吧，这个奇怪的地方的奇怪东西不知有啥奇怪用途。");
	_tcscpy_s(p[3], L"获得道具：神秘签字笔。");
	outputchar(p[0], 260, 600); char ch;
	mciSendString(_T("open music/收集成功物品.mp3 alias music"), NULL, 0, NULL);
	while (1) {
		flushmessage();
		if (_kbhit()) {
			ch = _getch();
			if (ch == ' ') {
				b[3] = 1;
				a[*x1][*y1] = 0;
				shuchu(a, *x1, *y1, *x2, *y2);
				break;
			}
		}
		if (MouseHit()) {
			MOUSEMSG msg = GetMouseMsg();
			if (msg.uMsg == WM_LBUTTONDOWN) {
				if (n > 3) {
					b[3] = 1;
					a[*x1][*y1] = 0;
					shuchu(a, *x1, *y1, *x2, *y2);
					break;
				}
				BeginBatchDraw();
				shuchu(a, *x1, *y1, *x2, *y2);
				putimage(0, 0, &P2, SRCAND);
				putimage(0, 0, &P1, SRCPAINT);
				putimage(220, 550, &P4, SRCAND);
				putimage(220, 550, &P3, SRCPAINT);
				EndBatchDraw();
				outputchar(p[n], 260, 600);
				if(n==3)mciSendString(_T("play music "), NULL, 0, NULL);
				n = n + 1;
			}
		}
	}
	mciSendString(_T("close music "), NULL, 0, NULL);
}