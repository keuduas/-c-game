#include<string.h>
#include<graphics.h>
#include<time.h>
#include<conio.h>
void shijian16(int a[32][18], int* x1, int* y1, int* x2, int* y2, int b[17]) {
	void outputchar(TCHAR str[], int x, int y);
	void shuchu(int a[32][18], int x, int y, int x2, int y2);
	IMAGE P1; IMAGE P2; IMAGE P3; IMAGE P4;
	loadimage(&P1, _T("image/����Ⱦ.png"), 450, 800);
	loadimage(&P2, _T("image/����1.png"), 450, 800);
	loadimage(&P3, _T("image/�ı���.png"), 680, 240);
	loadimage(&P4, _T("image/����6.png"), 680, 240);
	putimage(0, 0, &P2, SRCAND);
	putimage(0, 0, &P1, SRCPAINT);
	putimage(220, 550, &P4, SRCAND);
	putimage(220, 550, &P3, SRCPAINT);
	TCHAR p[10][100]; TCHAR q[10][100]; int n = 1;
	_tcscpy_s(p[0], L"����Ⱦ������ʲô�ط����ֿ���");
	_tcscpy_s(p[1], L"����Ⱦ����ô����ط�λ�õ������ƫ��");
	_tcscpy_s(p[2], L"����Ⱦ���򲻿������˰ɣ�������׷�����ء�");
	_tcscpy_s(q[0], L"����Ⱦ����ط����������ý��ҿ��򿪰ɡ�");
	_tcscpy_s(q[1], L"����Ⱦ�������ܡ�");
	_tcscpy_s(q[2], L"�ֿ��Ŵ��ˡ�");
	mciSendString(_T("open music/����.mp3 alias music"), NULL, 0, NULL);
	if (b[9] == 0) {
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
	else if (b[9] == 1) {
		outputchar(q[0], 260, 600); char ch;
		while (1) {
			flushmessage();
			if (_kbhit()) {
				ch = _getch();
				if (ch == ' ') {
					a[12][15] = 3; a[13][15] = 3;
					a[12][16] = 0; a[13][16] = 0;
					shuchu(a, *x1, *y1, *x2, *y2);
					break;
				}
			}
			if (MouseHit()) {
				MOUSEMSG msg = GetMouseMsg();
				if (msg.uMsg == WM_LBUTTONDOWN) {
					if (n > 2) {
						a[12][15] = 3; a[13][15] = 3;
						a[12][16] = 0; a[13][16] = 0;
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
					if(n==2)mciSendString(_T("play music"), NULL, 0, NULL);
					n = n + 1;
				}
			}
		}
	}
	mciSendString(_T("close music"), NULL, 0, NULL);
}