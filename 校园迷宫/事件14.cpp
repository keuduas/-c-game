#include<string.h>
#include<graphics.h>
#include<time.h>
#include<conio.h>
void shijian14(int a[32][18], int* x1, int* y1, int* x2, int* y2, int b[17]) {
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
	TCHAR p[10][100]; TCHAR q[10][100]; int n = 1;
	_tcscpy_s(p[0], L"陶行染：这是，高数教室？门怎么也锁上了。");
	_tcscpy_s(p[1], L"陶行染：门倒是挺结实的，看来得找钥匙了。");
	_tcscpy_s(p[2], L"陶行染：打卡机倒还在，我最讨厌这玩意了。");
	_tcscpy_s(q[0], L"陶行染：也没找到钥匙，这到底咋打开呀。");
	_tcscpy_s(q[1], L"陶行染：话说现在打个卡会咋样呢，有打卡记录吗？");
	_tcscpy_s(q[2], L"陶行染：啥，刷卡把门刷开了，这怎么可能，没道理的呀！");
	_tcscpy_s(q[3], L"教室门打开了。");
	mciSendString(_T("open music/开门.mp3 alias music"), NULL, 0, NULL);
	if (b[6] == 0) {
		outputchar(p[0], 260, 600); char ch;
		while (1) {
			flushmessage();
			if (_kbhit()) {
				ch = _getch();
				if (ch == ' ') {
					shuchu(a, *x1, *y1, *x2, *y2);
					break;
				}
			}
			if (MouseHit()) {
				MOUSEMSG msg = GetMouseMsg();
				if (msg.uMsg == WM_LBUTTONDOWN) {
					if (n > 2) {
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
					n = n + 1;
				}
			}
		}
	}
	else if (b[6] == 1) {
		outputchar(q[0], 260, 600); char ch;
		while (1) {
			if (_kbhit()) {
				ch = _getch();
				if (ch == ' ') {
					a[*x1][*y1] = 0;
					a[*x1][*y1-1] = 3;
					shuchu(a, *x1, *y1, *x2, *y2);
					break;
				}
			}
			if (MouseHit()) {
				MOUSEMSG msg = GetMouseMsg();
				if (msg.uMsg == WM_LBUTTONDOWN) {
					if (n > 3) {
						a[*x1][*y1] = 0;
						a[*x1][*y1-1] = 3;
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
					outputchar(q[n], 260, 600);
					if(n==3)mciSendString(_T("play music"), NULL, 0, NULL);
					n = n + 1;
				}
			}
		}
	}
	mciSendString(_T("close music"), NULL, 0, NULL);
}