#include<string.h>
#include<graphics.h>
#include<time.h>
#include<conio.h>
void shijian2(int a[32][18], int* x1, int* y1, int* x2, int* y2, int* c) {
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
	putimage(220, 550, &P4, SRCAND);
	putimage(220, 550, &P3, SRCPAINT);
	TCHAR p[7][100]; int n = 1; char ch;
	_tcscpy_s(p[0], L"����Ⱦ���ð���ѽ�������ҵ�ѧУ�𣿺���ֵĲ���ѽ��");
	_tcscpy_s(p[1], L"����Ⱦ���Ǳ��и��ˣ���˵��������£����˷������°ɡ���һ�£��ǲ�����һ����");
	_tcscpy_s(p[2], L"����Ⱦ����һ�㣿");
	_tcscpy_s(p[3], L"����Ⱦ����һ�㣬�������");
	_tcscpy_s(p[4], L"��һ������Ӧ���ڿ���Ŷ����ר�ĵĻ���ҿƵ�Ŷ��");
	_tcscpy_s(p[5], L"����Ⱦ�����ǣ�ʲô����������Ȼ�������ܰɣ�");
	_tcscpy_s(p[6], L"��ʾ�������һ��׷�𡣷���ᱻץ��ȥ���ԡ���һ�ᴩǽ��Ŷ��");
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