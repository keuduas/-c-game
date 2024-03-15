#include<string.h>
#include<graphics.h>
#include<time.h>
#include<conio.h>
#include<tchar.h>
void chushen(int a[32][18],int *x1,int *y1,int *x2,int *y2) {
	void outputchar(TCHAR str[], int x, int y);
	void shuchu(int a[32][18], int x, int y, int x2, int y2);
	IMAGE P1; IMAGE P2; IMAGE P3; IMAGE P4;
	loadimage(&P1, _T("image/陶行染.png"), 450, 800);
	loadimage(&P2, _T("image/遮罩1.png"), 450, 800);
	loadimage(&P3, _T("image/文本框.png"), 680, 240);
	loadimage(&P4, _T("image/遮罩6.png"), 680, 240);
	BeginBatchDraw();
	putimage(0, 0, &P2, SRCAND);
	putimage(0, 0, &P1, SRCPAINT);
	putimage(220, 550, &P4, SRCAND);
	putimage(220, 550, &P3, SRCPAINT);
	EndBatchDraw();
	TCHAR p[7][100]; int n=1;
	_tcscpy_s(p[0],L"陶行染：又是高数考试，我的脑袋都要被考坏了。");
	_tcscpy_s(p[1],L"陶行染：？话说，考场里为啥没其他人呀？");
	_tcscpy_s(p[2],L"陶行染：不对呀，这考场怎么这么小，话说今天几号来着，我为啥要考高数呀？");
	_tcscpy_s(p[3],L"陶行染：什么情况，我怎么突然啥也想不起来了，我啥时候来考试的来着。");
	_tcscpy_s(p[4],L"陶行染：不会吧，不会吧，灵异事件？不对不对，我现在应该专心考试才对。对，做题！别多想。");
	_tcscpy_s(p[5],L"陶行染：啊，受不了了，果然还是冷静不下来呀，四处探索一下吧，怎么会有连监考老师都没有的考场呢？");
	_tcscpy_s(p[6],L"提示：WASD移动，空格对有星星的地板互动。");
	outputchar(p[0], 260, 600); char ch;
	while(1){
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
				if (n > 6) {
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