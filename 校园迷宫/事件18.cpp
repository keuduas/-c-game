#include<string.h>
#include<graphics.h>
#include<time.h>
#include<conio.h>
#include<windows.h>
void shijian18(int a[32][18], int* x1, int* y1, int* x2, int* y2) {
	void outputchar(TCHAR str[], int x, int y);
	void shuchu(int a[32][18], int x, int y, int x2, int y2);
	IMAGE P1; IMAGE P2; IMAGE P3; IMAGE P4; IMAGE P5; IMAGE P6;
	loadimage(&P1, _T("image/����Ⱦ.png"), 450, 800);
	loadimage(&P2, _T("image/����1.png"), 450, 800);
	loadimage(&P3, _T("image/�ı���.png"), 680, 240);
	loadimage(&P4, _T("image/����6.png"), 680, 240);
	loadimage(&P5, _T("image/ƫ����һ.png"), 450, 800);
	loadimage(&P6, _T("image/����2.png"), 450, 800);
	putimage(0, 0, &P2, SRCAND);
	putimage(0, 0, &P1, SRCPAINT);
	putimage(670, 0, &P6, SRCAND);
	putimage(670, 0, &P5, SRCPAINT);
	putimage(220, 550, &P4, SRCAND);
	putimage(220, 550, &P3, SRCPAINT);
	TCHAR p[5][100]; int n = 1; char ch;
	_tcscpy_s(p[0], L"����Ⱦ����һ�㣬��һ�£���Ҫ����");
	_tcscpy_s(p[1], L"��һ�����ԹԻ�ȥ����Ŷ������Ҫ�ҿƵ�Ŷ��");
	_tcscpy_s(p[2], L"����Ⱦ����һ�£�");
	_tcscpy_s(p[3], L"����Ⱦ���ղŷ���ʲô���ˣ���˵��Ϊɶ�ڿ�����ѽ��");
	_tcscpy_s(p[4], L"����Ⱦ������ѽ���Һ���Ҫ��ɶ���š�");
	outputchar(p[0], 260, 600);
	mciSendString(_T("open music/����.mp3 alias music"), NULL, 0, NULL);
	mciSendString(_T("play music "), NULL, 0, NULL);
	
	while (1) {
		flushmessage();
		if (_kbhit()) {
			ch = _getch();
			if (ch == ' ') {
				*x1 = 4; *y1 = 4; *x2 = 14; *y2 = 4;
				shuchu(a, *x1, *y1, *x2, *y2);
				break;
			}
		}
	
		if (MouseHit()) {
			MOUSEMSG msg = GetMouseMsg();
			if (msg.uMsg == WM_LBUTTONDOWN) {
				if (n > 4) {
					shuchu(a, *x1, *y1, *x2, *y2);
					break;
				}
				if (n == 3) {
					cleardevice();
					Sleep(1000);
				}
				shuchu(a, *x1, *y1, *x2, *y2);
				BeginBatchDraw();
				putimage(0, 0, &P2, SRCAND);
				putimage(0, 0, &P1, SRCPAINT);
				if (n < 3) {
					putimage(670, 0, &P6, SRCAND);
					putimage(670, 0, &P5, SRCPAINT);
				}
				putimage(220, 550, &P4, SRCAND);
				putimage(220, 550, &P3, SRCPAINT);
				EndBatchDraw();
				outputchar(p[n], 260, 600);
				if (n == 2) {
					*x1 = 4; *y1 = 4; *x2 = 14; *y2 = 4;
				}
				n = n + 1;
			}
		}
	}
	mciSendString(_T("close music "), NULL, 0, NULL);
}