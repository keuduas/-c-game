#include<graphics.h>
void shuchu(int a[32][18],int x,int y,int x2,int y2) {
	int i, j;
	IMAGE P1; IMAGE P2; IMAGE P3; IMAGE P4; IMAGE P5; IMAGE P6; IMAGE P7; IMAGE P8; IMAGE P9; IMAGE P10;
	loadimage(&P1, _T("image/墙壁.png"), 160, 160);
	loadimage(&P2, _T("image/地板1.png"), 160, 160);
	loadimage(&P3, _T("image/地板2.png"), 160, 160);
	loadimage(&P4, _T("image/事件.png"), 160, 160);
	loadimage(&P5, _T("image/遮罩5.png"), 160, 160);
	loadimage(&P6, _T("image/陶行染头像.png"), 160, 160);
	loadimage(&P7, _T("image/遮罩3.png"), 160, 160);
	loadimage(&P8, _T("image/李一头像.png"), 160, 160);
	loadimage(&P9, _T("image/遮罩4.png"), 160, 160);
	loadimage(&P10, _T("image/门.png"), 160, 160);
	for (i = 0; i < 7; i++) {
		for (j = 0; j < 5; j++) {
			if ((x - 3 + i) >= 0 && (x - 3 + i) < 32 && (y - 2 + j) < 18 && (y - 2 + j) >= 0) {
				if (a[x - 3 + i][y - 2 + j] == 1) {
					putimage(i * 160, j * 160, &P3);
				}
				else if (a[x - 3 + i][y - 2 + j] == 0 || a[x - 3 + i][y - 2 + j] == 2 || a[x - 3 + i][y - 2 + j] == 5) {
					putimage(i * 160, j * 160, &P2);
				}
				else if (a[x - 3 + i][y - 2 + j] == 3) {
					putimage(i * 160, j * 160, &P1);
				}
				else if (a[x - 3 + i][y - 2 + j] == 4 || a[x - 3 + i][y - 2 + j] == 7 || a[x - 3 + i][y - 2 + j] == 9 || a[x - 3 + i][y - 2 + j] == 10 || a[x - 3 + i][y - 2 + j] == 11 || a[x - 3 + i][y - 2 + j] == 12 || a[x - 3 + i][y - 2 + j] == 13 || a[x - 3 + i][y - 2 + j] == 14 || a[x - 3 + i][y - 2 + j] == 15 || a[x - 3 + i][y - 2 + j] == 21) {
					putimage(i * 160, j * 160, &P1);
					putimage(i * 160, j * 160, &P5, SRCAND);
					putimage(i * 160, j * 160, &P4, SRCPAINT);
				}
				else if (a[x - 3 + i][y - 2 + j] == 6 || a[x - 3 + i][y - 2 + j] == 8 || a[x - 3 + i][y - 2 + j] == 16 || a[x - 3 + i][y - 2 + j] == 18 || a[x - 3 + i][y - 2 + j] == 19 || a[x - 3 + i][y - 2 + j] == 20) {
					putimage(i * 160, j * 160, &P2);
					putimage(i * 160, j * 160, &P5, SRCAND);
					putimage(i * 160, j * 160, &P4, SRCPAINT);
				}
				else if (a[x - 3 + i][y - 2 + j] == 17) {
					putimage(i * 160, j * 160, &P10);
				}
			}
			else {
				setfillcolor(BLACK);
				solidrectangle((i * 160), (j * 160), (i * 160+160), (j * 160 + 160));
			}
		}
	}
	putimage(480, 320, &P7, SRCAND);
	putimage(480, 320, &P6, SRCPAINT);
	putimage((x2 - x + 3) * 160, (y2 - y + 2) * 160, &P9, SRCAND);
	putimage((x2 - x + 3) * 160, (y2 - y + 2) * 160, &P8, SRCPAINT);
}