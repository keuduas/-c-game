#include<cstdlib>
void ditu(int a[32][18]) {
	int i, j, x, y;
	void fangjian1(int a[32][18], int x, int y);
	void fangjian2(int a[32][18], int x, int y);
	void fangjian3(int a[32][18], int x, int y);
	void fangjian4(int a[32][18], int x, int y);
	void fangjian5(int a[32][18], int x, int y);
	void fangjian6(int a[32][18], int x, int y);
	void fangjian7(int  a[32][18], int x, int y);
	for (i = 0; i < 32; i++) {
		for (j = 0; j < 18; j++) {
			if (i == 0 || i == 31 || j == 0 || j == 17) {
				a[i][j] = 1;
			}
			else {
				a[i][j] = 0;
			}
		}
	}
	fangjian1(a, 1, 1);
	fangjian2(a, 7, 1);
	fangjian7(a, 11, 1);
	fangjian3(a, 19, 1);
	fangjian4(a, 1, 9);
	fangjian5(a, 8, 7);
	fangjian6(a, 19, 9);
	a[30][16] = 6;
	a[31][8] = 17;
	a[31][9] = 17;
	a[30][8] = 16;
	a[30][9] = 16;
}