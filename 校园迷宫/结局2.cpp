#include<string.h>
#include<graphics.h>
#include<conio.h>
void jieju2() {
	void outputchar(TCHAR str[], int x, int y);
	IMAGE P1; IMAGE P2; IMAGE P3; IMAGE P4; IMAGE P5; IMAGE P6; IMAGE P7;
	loadimage(&P1, _T("image/陶行染.png"), 450, 800);
	loadimage(&P2, _T("image/遮罩1.png"), 450, 800);
	loadimage(&P3, _T("image/文本框.png"), 680, 240);
	loadimage(&P4, _T("image/遮罩6.png"), 680, 240);
	loadimage(&P5, _T("image/李一.png"), 450, 800);
	loadimage(&P6, _T("image/遮罩2.png"), 450, 800);
	loadimage(&P7, _T("image/教室.png"), 1120, 800);
	cleardevice();
	putimage(220, 550, &P4, SRCAND);
	putimage(220, 550, &P3, SRCPAINT);
	TCHAR p[10][100]; char ch; int n = 1;
	_tcscpy_s(p[0],L"迷迷糊糊中，陶行染听到了一阵呼喊声");
	_tcscpy_s(p[1],L"醒醒，高数都考完了，你睡了大半场考试了！");
	_tcscpy_s(p[2], L"陶行染：啥！我不会要挂科了吧！");
	_tcscpy_s(p[3], L"李一：耍你的，高数课上就知道睡觉，期末还叫我帮你补课，下课啦，走啦。");
	_tcscpy_s(p[4], L"陶行染：嘿嘿，李一姐你最好了，对了，我刚才做了一个很奇怪的梦，真的很奇怪——");
	_tcscpy_s(p[5], L"达成真结局，完。");
	outputchar(p[0], 260, 600);
	while (1) {
		if (MouseHit()) {
			MOUSEMSG msg = GetMouseMsg();
			if (msg.uMsg == WM_LBUTTONDOWN) {
				if (n > 5) {
					closegraph();
					break;
				}
				else if (n > 1) {
					BeginBatchDraw();
					putimage(0, 0, &P7);
					putimage(0, 0, &P2, SRCAND);
					putimage(0, 0, &P1, SRCPAINT);
					putimage(670, 0, &P6, SRCAND);
					putimage(670, 0, &P5, SRCPAINT);
					putimage(220, 550, &P4, SRCAND);
					putimage(220, 550, &P3, SRCPAINT);
					EndBatchDraw();
				}
				else {
					putimage(220, 550, &P4, SRCAND);
					putimage(220, 550, &P3, SRCPAINT);
				}
				outputchar(p[n], 260, 600);
				n = n + 1;
			}
		}
	}
}