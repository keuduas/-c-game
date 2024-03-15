#include<graphics.h>
#include<windows.h>
void outputchar(TCHAR str[], int x, int y)
{   
	flushmessage();
	settextcolor(BLACK); int n = 0;
	setbkmode(TRANSPARENT);
	settextstyle(30, 15, _T("ºÚÌå"));
	for (int i = 0, m = 0; i < _tcslen(str); )
	{   
		if (MouseHit()) {
			MOUSEMSG msg = GetMouseMsg();
			if (msg.uMsg == WM_LBUTTONDOWN) {
				n = 1;
			}
		}
		if ((x + m * 30) >= 800)
		{
			m = 0; y += 30;
		}

		outtextxy(x + m * 30, y, str[i]);
		i ++; m++;
		if (n == 0) {
			Sleep(50);
		}
	}
}
