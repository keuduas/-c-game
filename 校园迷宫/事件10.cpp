#include<string.h>
#include<graphics.h>
#include<time.h>
#include<conio.h>
void shijian10(int a[32][18], int* x1, int* y1, int* x2, int* y2, int b[17]) {
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
	_tcscpy_s(p[0], L"陶行染：老师的办公室到挺干净的，真是的，这到底是哪呀？");
	_tcscpy_s(p[1], L"陶行染：电脑居然是开着的！");
	_tcscpy_s(p[2], L"陶行染：网络也连不上，文件也少的可怜，等一下，为啥年代奇奇怪怪的，一会1990，一会2020的。");
	_tcscpy_s(p[3], L"陶行染：等一下，这串数字，难道说！");
	_tcscpy_s(p[4], L"获得道具：神秘数字。");
	mciSendString(_T("open music/收集成功物品.mp3 alias music"), NULL, 0, NULL);
	outputchar(p[0], 260, 600); char ch;
	while (1) {
		flushmessage();
		if (_kbhit()) {
			ch = _getch();
			if (ch == ' ') {
				b[10] = 1;
				a[*x1][*y1] = 3;
				shuchu(a, *x1, *y1, *x2, *y2);
				break;
			}
		}
		if (MouseHit()) {
			MOUSEMSG msg = GetMouseMsg();
			if (msg.uMsg == WM_LBUTTONDOWN) {
				if (n > 4) {
					b[10] = 1;
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