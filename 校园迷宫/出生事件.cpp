#include<string.h>
#include<graphics.h>
#include<time.h>
#include<conio.h>
#include<tchar.h>
void chushen(int a[32][18],int *x1,int *y1,int *x2,int *y2) {
	void outputchar(TCHAR str[], int x, int y);
	void shuchu(int a[32][18], int x, int y, int x2, int y2);
	IMAGE P1; IMAGE P2; IMAGE P3; IMAGE P4;
	loadimage(&P1, _T("image/����Ⱦ.png"), 450, 800);
	loadimage(&P2, _T("image/����1.png"), 450, 800);
	loadimage(&P3, _T("image/�ı���.png"), 680, 240);
	loadimage(&P4, _T("image/����6.png"), 680, 240);
	BeginBatchDraw();
	putimage(0, 0, &P2, SRCAND);
	putimage(0, 0, &P1, SRCPAINT);
	putimage(220, 550, &P4, SRCAND);
	putimage(220, 550, &P3, SRCPAINT);
	EndBatchDraw();
	TCHAR p[7][100]; int n=1;
	_tcscpy_s(p[0],L"����Ⱦ�����Ǹ������ԣ��ҵ��Դ���Ҫ�������ˡ�");
	_tcscpy_s(p[1],L"����Ⱦ������˵��������Ϊɶû������ѽ��");
	_tcscpy_s(p[2],L"����Ⱦ������ѽ���⿼����ô��ôС����˵���켸�����ţ���ΪɶҪ������ѽ��");
	_tcscpy_s(p[3],L"����Ⱦ��ʲô���������ôͻȻɶҲ�벻�����ˣ���ɶʱ�������Ե����š�");
	_tcscpy_s(p[4],L"����Ⱦ������ɣ�����ɣ������¼������Բ��ԣ�������Ӧ��ר�Ŀ��ԲŶԡ��ԣ����⣡����롣");
	_tcscpy_s(p[5],L"����Ⱦ�������ܲ����ˣ���Ȼ�����侲������ѽ���Ĵ�̽��һ�°ɣ���ô�������࿼��ʦ��û�еĿ����أ�");
	_tcscpy_s(p[6],L"��ʾ��WASD�ƶ����ո�������ǵĵذ廥����");
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