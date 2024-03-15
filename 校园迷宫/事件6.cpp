#include<string.h>
#include<graphics.h>
#include<time.h>
#include<conio.h>
void shijian6(int a[32][18], int* x1, int* y1, int* x2, int* y2, int b[17]) {
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
	TCHAR p[5][100]; int n = 1;
	_tcscpy_s(p[0], L"陶行染：我的床，怎么这么脏呀！");
	_tcscpy_s(p[1], L"陶行染：这些是我的书吗？确实是我的笔记，但怎么这么旧呀！都发黄了。");
	_tcscpy_s(p[2], L"陶行染：我不会是穿越到未来了吧！");
	_tcscpy_s(p[3], L"陶行染：我的学生卡，到挺干净的，带回去吧。");
	_tcscpy_s(p[4], L"获得道具：学生卡。");
	mciSendString(_T("open music/收集成功物品.mp3 alias music"), NULL, 0, NULL);
	outputchar(p[0], 260, 600); char ch;
	while (1) {
		flushmessage();
		if (_kbhit()) {
			ch = _getch();
			if (ch == ' ') {
				b[6] = 1;
				a[*x1][*y1] = 3;
				shuchu(a, *x1, *y1, *x2, *y2);
				break;
			}
		}
		if (MouseHit()) {
			MOUSEMSG msg = GetMouseMsg();
			if (msg.uMsg == WM_LBUTTONDOWN) {
				if (n > 4) {
					b[6] = 1;
					a[*x1][*y1] = 3;
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
				if(n==4)
				mciSendString(_T("play music "), NULL, 0, NULL);
				n = n + 1;
			}
		}
	}
	mciSendString(_T("close music "), NULL, 0, NULL);
}