#include<graphics.h>
#include<windows.h>
#include<conio.h>
#include<stdio.h>
#include"±êÍ·.h"
int main() 
{
	int a[32][18]; int x1, y1, x2, y2, n, i , c=0; char ch;
	int b[17]; for (i = 0; i < 17; i++) {
		b[i] = 0;
	}
	initgraph(1120, 800);
	kaichang();
	setbkcolor(BLACK);
	cleardevice();
	x1 = 4; y1 = 4; x2 = 14; y2 = 7; n = 0;
	ditu(a);
	mciSendString(_T("open music/ÓÎÏ·ÒôÀÖ.mp3 alias bkmusic"), NULL, 0, NULL);
	mciSendString(_T("play bkmusic repeat"), NULL, 0, NULL);
	shuchu(a, x1, y1, x2, y2);
	chushen(a,&x1,&y1,&x2,&y2);
	while (1) 
	{
		if (_kbhit()) {
			ch = _getch();
			if (ch == 'A' || ch == 'a') {
				if (a[x1 - 1][y1] != 1 && a[x1 - 1][y1] != 17) {
					left(a, x1, y1, x2, y2);
					x1 = x1 - 1;
					n = n + 1;
					shenpan(a, &x1, &y1, &x2, &y2, &c);
					if (n % 2 == 0 && c == 1) {
						zhuizhujisuan(x1, y1, &x2, &y2);
					}
				}
				while (_kbhit()) {
					_getch();
				}
			}
			else if (ch == 'd' || ch == 'D') {
				if (a[x1 + 1][y1] != 1 && a[x1 + 1][y1] != 17) {
					right(a, x1, y1, x2, y2);
					x1 = x1 + 1;
					n = n + 1;
					shenpan(a, &x1, &y1, &x2, &y2, &c);
					if (n % 2 == 0&&c==1) {
						zhuizhujisuan(x1, y1, &x2, &y2);
					}
				}
				while (_kbhit()) {
					_getch();
				}
			}
			else if (ch == 'W' || ch == 'w') {
				if (a[x1][y1 - 1] != 1 && a[x1][y1 - 1] != 17) {
					up(a, x1, y1, x2, y2);
					y1 = y1 - 1;
					n = n + 1;
					shenpan(a, &x1, &y1, &x2, &y2, &c);
					if (n % 2 == 0 && c == 1) {
						zhuizhujisuan(x1, y1, &x2, &y2);
					}
				}
				while (_kbhit()) {
					_getch();
				}
			}
			else if (ch == 'S' || ch == 's') {
				if (a[x1][y1 + 1] != 1 && a[x1][y1 + 1] != 17) {
					down(a, x1, y1, x2, y2);
					y1 = y1 + 1;
					n = n + 1;
					shenpan(a, &x1, &y1, &x2, &y2, &c);
					if (n % 2 == 0 && c == 1) {
						zhuizhujisuan(x1, y1, &x2, &y2);
					}
				}
				while (_kbhit()) {
					_getch();
				}
			}
			else if (ch == ' ') {
				panduan(a, &x1, &y1, &x2, &y2, b);
				while (_kbhit()) {
					_getch();
				}
			}
		}
	}

	mciSendString(_T("close bkmusic "), NULL, 0, NULL);
}