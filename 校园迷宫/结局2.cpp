#include<string.h>
#include<graphics.h>
#include<conio.h>
void jieju2() {
	void outputchar(TCHAR str[], int x, int y);
	IMAGE P1; IMAGE P2; IMAGE P3; IMAGE P4; IMAGE P5; IMAGE P6; IMAGE P7;
	loadimage(&P1, _T("image/����Ⱦ.png"), 450, 800);
	loadimage(&P2, _T("image/����1.png"), 450, 800);
	loadimage(&P3, _T("image/�ı���.png"), 680, 240);
	loadimage(&P4, _T("image/����6.png"), 680, 240);
	loadimage(&P5, _T("image/��һ.png"), 450, 800);
	loadimage(&P6, _T("image/����2.png"), 450, 800);
	loadimage(&P7, _T("image/����.png"), 1120, 800);
	cleardevice();
	putimage(220, 550, &P4, SRCAND);
	putimage(220, 550, &P3, SRCPAINT);
	TCHAR p[10][100]; char ch; int n = 1;
	_tcscpy_s(p[0],L"���Ժ����У�����Ⱦ������һ�������");
	_tcscpy_s(p[1],L"���ѣ������������ˣ���˯�˴�볡�����ˣ�");
	_tcscpy_s(p[2], L"����Ⱦ��ɶ���Ҳ���Ҫ�ҿ��˰ɣ�");
	_tcscpy_s(p[3], L"��һ��ˣ��ģ��������Ͼ�֪��˯������ĩ�����Ұ��㲹�Σ��¿�����������");
	_tcscpy_s(p[4], L"����Ⱦ���ٺ٣���һ��������ˣ����ˣ��Ҹղ�����һ������ֵ��Σ���ĺ���֡���");
	_tcscpy_s(p[5], L"������֣��ꡣ");
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