#include<string.h>
#include<graphics.h>
#include<conio.h>
void jieju1() {
	void outputchar(TCHAR str[], int x, int y);
	IMAGE P1; IMAGE P2;
	loadimage(&P1, _T("image/文本框.png"), 680, 240);
	loadimage(&P2, _T("image/遮罩6.png"), 680, 240);
	cleardevice();
	putimage(220, 550, &P2, SRCAND);
	putimage(220, 550, &P1, SRCPAINT);
	TCHAR p[10][100]; char ch; int n=1;
	_tcscpy_s(p[0], L"打开了这扇大门之后，陶行染已经不记得有关这的一切了。");
	_tcscpy_s(p[1], L"大学的生活简单而又充实，很快四年就过去了。");
	_tcscpy_s(p[2], L"唯一让她奇怪的是，为啥四人间的宿舍只有三个人。");
	_tcscpy_s(p[3], L"达成结局。完？");
	outputchar(p[0], 260, 600);
	while (1) {
		if (MouseHit()) {
			MOUSEMSG msg = GetMouseMsg();
			if (msg.uMsg == WM_LBUTTONDOWN) {
				if (n > 3) {
					closegraph();
					break;
				}
				putimage(220, 550, &P2, SRCAND);
				putimage(220, 550, &P1, SRCPAINT);
				outputchar(p[n], 260, 600);
				n = n + 1;
			}
		}
	}
}