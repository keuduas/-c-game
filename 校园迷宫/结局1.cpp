#include<string.h>
#include<graphics.h>
#include<conio.h>
void jieju1() {
	void outputchar(TCHAR str[], int x, int y);
	IMAGE P1; IMAGE P2;
	loadimage(&P1, _T("image/�ı���.png"), 680, 240);
	loadimage(&P2, _T("image/����6.png"), 680, 240);
	cleardevice();
	putimage(220, 550, &P2, SRCAND);
	putimage(220, 550, &P1, SRCPAINT);
	TCHAR p[10][100]; char ch; int n=1;
	_tcscpy_s(p[0], L"�������ȴ���֮������Ⱦ�Ѿ����ǵ��й����һ���ˡ�");
	_tcscpy_s(p[1], L"��ѧ������򵥶��ֳ�ʵ���ܿ�����͹�ȥ�ˡ�");
	_tcscpy_s(p[2], L"Ψһ������ֵ��ǣ�Ϊɶ���˼������ֻ�������ˡ�");
	_tcscpy_s(p[3], L"��ɽ�֡��ꣿ");
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